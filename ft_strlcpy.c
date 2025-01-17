/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:22:39 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/26 18:01:11 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	ret;
	size_t	i;

	ret = ft_strlen(src);
	i = 0;
	if (destsize > 0)
	{
		while (i < destsize - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ret);
}

/*int	main(void)
{
	char	arrs[] = "ola";
	char	arrd[10];

	printf("%lu\n", ft_strlcpy(arrd, arrs, 15));
	printf("%s", arrd);
}*/