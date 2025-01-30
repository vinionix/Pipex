/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:31:59 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/29 23:24:56 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		ft_exe(char *cmd, char **env)
{
	char **cmd_valid;

	cmd_valid = malloc(sizeof(char *) * 4);
	cmd_valid[0] = "/bin/sh";
	cmd_valid[1] = "-c";
	cmd_valid[2] = cmd;
	cmd_valid[3] = NULL;
	execve("/bin/sh", cmd_valid, env);
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

static int	ft_redirect(char *cmd, char **env)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid)
		ft_dad(pid, pipefd);
	else
	{
		ft_son(pipefd);
		if (ft_exe(cmd, env) == -1)
			exit(1);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int	fd_in;
	int	fd_out;
	int	i = 0;

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
			if (ft_redirect(argv[i], env) == -1)
				exit(1);
			i++;
		}
		ft_exe(argv[i], env);
	}
	return (0);
}
