/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:31:59 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/16 18:18:25 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd;
	int		i;
	char	**path;

	path = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	if (argc >= 5)
	{
		while (ft_strncmp(env[i], "PATH=", 5) != 0)
			i++;
		path = ft_split(&env[i][5], ':');
		if (valid_cmd(argv, path) == 0)
			
	}
	return (0);
}
