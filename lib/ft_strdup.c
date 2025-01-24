/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:49:57 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/23 21:40:52 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*strcopy;
	size_t	length;
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	length = ft_strlen(str);
	strcopy = (char *)malloc(sizeof(char) * (length + 1));
	if (strcopy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		strcopy[i] = str[i];
		i++;
	}
	strcopy[i] = '\0';
	return (strcopy);
}

/*int	main(void)
{
	char	*copy = ft_strdup("Ola");

	if (copy != NULL)
	{
		printf("Copia = %s", copy);
		free(copy); //Memoria liberada.
	}
	else
	{
		printf("Falhou");
	}
}*/
