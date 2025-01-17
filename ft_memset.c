/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:56:46 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/12 17:56:59 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *string, int character, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		((unsigned char *)string)[i] = (unsigned char)character;
		i++;
	}
	return (string);
}

/*int	main(void)
{
	char	arr[10];

	printf("%s", (char *)ft_memset(arr, 65, 10));
}*/
