/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:31:59 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/23 23:08:04 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_son(char **cmd, char *path_valid, char **env)
{
	char		**cmd_execve;
	int			pipefd[2];
	int			fd_i;
	int			fd_o;

	
	cmd_execve = NULL;
	pipe(pipefd);
	if (ft_strncmp("./pipex", *(cmd - 1), 7) == 0)
	{
		fd_i = open(cmd[0], O_RDWR);
		if (fd_i == -1)
			return (fd_i);
		if (fork() == 0)
		{
			cmd_execve = ft_split(*(cmd + 1), ' ');
			dup2(fd_i, STDIN_FILENO);
			dup2(pipefd[1], STDOUT_FILENO);
			close(fd_i);
			close(pipefd[1]);
			execve(path_valid, cmd_execve, env);
		}
		return (0);
	}
	else if (*(cmd + 3) == NULL)
	{
		fd_o = open(*(cmd + 1), O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_o == -1)
			return (-1);
		if (fork() == 0)
		{
			cmd_execve = ft_split(*(cmd + 1), ' ');
			dup2(pipefd[0], STDIN_FILENO);
			dup2(fd_o, STDOUT_FILENO);
			close(fd_o);
			close(pipefd[0]);
			execve(path_valid, cmd_execve, env);
		}
			printf("p");
		return (0);
	}
	else if (fork() == 0)
	{
		cmd_execve = ft_split(*(cmd), ' ');
		dup2(pipefd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(path_valid, cmd_execve, env);
	}
	printf("p");
	return (0);
}

void	ft_dad(char **argv, int argc, char **env)
{
	char	**path;
	char	**cmd_path;
	int		i;

	i = 1;
	path = get_path(env);
	cmd_path = valid_cmd(argv + 1, path, argc - 3);
	if (cmd_path == NULL)
	{
		ft_free(path);
		exit(1);
	}
	while(argv[i + 2] != NULL)
	{
		ft_son(&argv[i], cmd_path[i], env);
		i++;
	}
			while(i >= 0)
			{
				wait(NULL);
				i--;
			}
	ft_free(path);
	ft_free(cmd_path);
}

int	main(int argc, char **argv, char **env)
{
	int	fd;

	fd = 0;
	if (argc >= 5)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("Error");
			close(fd);
			exit(1);
		}
		close(fd);
		ft_dad(argv, argc, env);
	}
	return (0);
}
