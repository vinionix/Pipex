/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:38:13 by vfidelis          #+#    #+#             */
/*   Updated: 2024/10/07 15:38:17 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	receptor;

	receptor = n;
	if (receptor < 0)
	{
		receptor *= -1;
		write(fd, "-", 1);
	}
	if (receptor >= 10)
	{
		ft_putnbr_fd(receptor / 10, fd);
		ft_putnbr_fd(receptor % 10, fd);
	}
	else if (receptor >= 0 && receptor <= 9)
	{
		receptor = receptor + '0';
		write(fd, &receptor, 1);
	}
}

/*int main()
{
	ft_putnbr_fd(9, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(10, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(2147483647, 1);
}*/