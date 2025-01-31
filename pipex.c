/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:31:59 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/30 23:35:45 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char 	**path;
	int		i;

	i = 0;
	path = NULL;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(&env[i][5], ':');
	return (path);
}

static int	valid_path(char *cmd, char **path)
{
	int		j;
	char	*receiver;

	receiver = NULL;
	j = 0;
	while(path[j])
	{
		if (ft_strncmp(cmd, path[j], ft_strlen(cmd)) == 0 || ft_strncmp(cmd, "sudo", 4) == 0)
			return (-2);
		j++;
	}
	if (access(cmd, X_OK | F_OK) == 0)
		return (0);
	j = 0;
	while (path[j])
	{
		receiver = ft_strjoin(path[j], cmd);
		if (access(receiver, X_OK | F_OK) == 0)
		{
			free(receiver);
			return (0);
		}
		free(receiver);
		j++;
	}
	return (-1);
}

static void	ft_exe(char *cmd, char **env)
{
	char	**cmd_valid;
	int		i;
	char	**path;

	path = get_path(env);
	i = 0;
	if (valid_path(cmd, path) == -1)
	{
		write(2, "Pipex: command not found: ", 27);
		write(2, cmd, ft_strlen(cmd));
	}
	else if (valid_path(cmd, path) == -2)
		write(2, "Pipex: permission denied", 25);
	exit(127);
	while(path[i])
		free(path[i++]);
	free(path);
	cmd_valid = malloc(sizeof(char *) * 4);
	cmd_valid[0] = "/bin/sh";
	cmd_valid[1] = "-c";
	cmd_valid[2] = cmd;
	cmd_valid[3] = NULL;
	execve("/bin/sh", cmd_valid, env);
}

static int	ft_redirect(char *cmd, char **env)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(pid, NULL, 0);
	}
	else
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		close(pipefd[0]);
		ft_exe(cmd, env);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int	fd_in;
	int	fd_out;
	int	i;

	i = 2;
	if (argc == 5)
	{
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in < 0)
		{
			perror("Pipex");
			exit(1);
		}
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_in);
		close(fd_out);
		while (argv[i + 2] != NULL)
		{
			if (ft_redirect(argv[i], env) == -1)
				exit(1);
			i++;
		}
		ft_exe(argv[i], env);
	}
	return (0);
}
