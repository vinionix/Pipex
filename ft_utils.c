/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:28:50 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/16 18:26:39 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	valid_cmd(char **cmd, char **path)
{
	int		exist;
	int		i;
	int		j;
	size_t	len;
	char	*receiver;

	receiver = NULL;
	i = 2;
	j = 0;
	while(cmd[i + 1] != NULL)
	{
		while (path[j])
		{
			len = ft_strlen(path[j]);
			if (ft_strncmp(cmd[i], path[j], len) == 0)
				exist = access(cmd[i], F_OK | R_OK);
			else
			{
				receiver = ft_strjoin(path[j], cmd[i]);
				printf("%s\n", receiver);
				exist = access(receiver, F_OK | R_OK);
			}
			if (exist == 0)
				break ;
			j++;
		}
		j = 0;
		if (exist != 0)
		{
			perror("Error");
			return (-1);
		}
		i++;
	}
	return (0);
}

void	execute_cmd(**cmd, char **path)
{
	
}