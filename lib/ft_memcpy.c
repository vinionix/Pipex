/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:53:24 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/12 15:18:19 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	int		main_src;
	char	main_dest[20];
	int		main_src2;
	char	main_dest2[20];

	main_src = 65;
	main_src2 = 65;
	ft_memcpy(main_dest, &main_src, 5);
	printf("main_dest:%s\n", main_dest);
	//memcpy original
	memcpy(main_dest2, &main_src2, 12);
	printf("main_dest2: %s\n", main_dest2);
}*/
