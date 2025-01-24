/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:57:50 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/23 22:42:42 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include "lib/libft.h"

int     ft_son(char **cmd, char *path_valid, char **env);
char	**get_path(char **env);
char	**valid_cmd(char **cmd, char **path, int argc);
void	ft_dad(char **argv, int argc, char **env);

#endif