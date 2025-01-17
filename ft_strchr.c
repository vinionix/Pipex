/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:49:57 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/23 21:40:52 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*int main()
{
	const char *str = "Hello, world!";
	char c = 'a';

	char *result = ft_strchr(str, c);
	if (result)
		printf("Caractere '%c' encontrado na posição: %ld\n", c, result - str);
	else
		printf("Caractere '%c' não encontrado.\n", c);

	return (0);
}*/
