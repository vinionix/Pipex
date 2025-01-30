/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:28:50 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/29 22:27:22 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*valid_path(char **path, char *cmd)
{
	int		j;
	char	*receiver;
		
	receiver = NULL;
	j = 0;
	//if (ft_strrchr())
	while (path[j])
	{
		if (access(cmd, F_OK | R_OK | X_OK) == 0)
			return (cmd);
		else if (access(cmd, F_OK | R_OK | X_OK) == -1)
		{
			receiver = ft_strjoin(path[j], cmd);
			if (access(receiver, F_OK | R_OK) == 0)
				return (receiver);
			else
				free(receiver);
		}
		j++;
	}
	return (NULL);
}

char	**valid_cmd(char **cmd, char **path, int argc)
{
	int		i;
	int		j;
	char	**cmd_valid;

	j = 0;
	i = 1;
	cmd_valid = malloc(sizeof(char *) * (argc + 1));
	cmd_valid[argc] = NULL;
	while(cmd[i + 1] != NULL)
	{
		cmd_valid[j] = valid_path(path, cmd[i]);
		if (cmd_valid[j] == NULL)
		{
			write(2, cmd[i], ft_strlen(cmd[i]));
			write(2, ": command not found", 19);
			ft_free(cmd_valid);
			return (NULL);
		}
		j++;
		i++;
	}
	return (cmd_valid);
}

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
