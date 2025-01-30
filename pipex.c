/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:31:59 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/29 22:28:21 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		ft_exe(char **cmd_valid, char *path_valid, char **env)
{
	execve(path_valid, cmd_valid, env);
	perror("fodeu");
	exit(127);
}

static void	ft_son(int *pipefd)
{
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
}

static void	ft_dad(int pid, int *pipefd)
{
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid, NULL, 0);
}

static int	ft_redirect(char *cmd, char *path_valid, char **env)
{
	pid_t	pid;
	int		pipefd[2];
	char	**cmd_valid;

	cmd_valid = ft_split(cmd, ' ');
	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid)
		ft_dad(pid, pipefd);
	else
	{
		ft_son(pipefd);
		if (ft_exe(cmd_valid, path_valid, env) == -1)
			exit(1);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int	fd_in;
	int	fd_out;
	int	i = 0;
	char	**path_valid;
	char	**get;

	get = get_path(env);
	path_valid = valid_cmd(argv + 1, get, argc - 3);
	if (path_valid == NULL)
	{
		ft_free(get);
		perror("Error");
		exit(1);
	}
	i = 2;
	fd_in = 0;
	fd_out = 0;
	if (argc >= 5)
	{
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in < 0)
		{
			perror("Error");
			exit(1);
		}
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_in);
		close(fd_out);
		while (argv[i + 2] != NULL)
		{
			if (ft_redirect(argv[i], path_valid[i - 2], env) == -1)
				exit(1);
			i++;
		}
		ft_exe(ft_split(argv[i], ' '), path_valid[i - 2], env);
	}
	return (0);
}
