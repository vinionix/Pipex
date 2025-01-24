/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:19:46 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/29 17:17:04 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lens;
	size_t	lend;
	size_t	j;
	size_t	i;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size == lend)
		return (lend + lens);
	if (size < lend)
		return (size + lens);
	i = 0;
	j = lend;
	while (j < size - 1 && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (lend + lens);
}

/*int main()
{
	char	arrd[15] = "abcdefghi ";
	char	arrs[] = "abcdefghijk";
	printf("%zu", ft_strlcat(arrd, arrs, 9));
	printf("%s", arrd);
}*/
