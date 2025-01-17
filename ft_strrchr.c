/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:49:57 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/23 21:40:52 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)&str[i]);
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
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