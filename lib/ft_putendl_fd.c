/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:25:36 by vfidelis          #+#    #+#             */
/*   Updated: 2024/10/07 15:25:38 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	count;

	count = ft_strlen(s);
	write(fd, s, count);
	write(fd, "\n", 1);
}

/*int main()
{
	ft_putendl_fd("Ola", 1);
}*/