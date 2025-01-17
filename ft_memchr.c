/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:47:44 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/16 15:04:59 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int chr, size_t num)
{
	unsigned char	*ptrarr;
	size_t			i;
	unsigned char	convert;

	convert = (unsigned char)chr;
	i = 0;
	ptrarr = (unsigned char *)arr;
	while (i < num)
	{
		if (ptrarr[i] == convert)
			return (&ptrarr[i]);
		i++;
	}
	return (NULL);
}

/*int main() {
	char data[] = "Exemplo de string.";
	char *resultado;

	// Busca pelo caractere 'd' na string
	resultado = ft_memchr(data, 'd', sizeof(data));

	if (resultado != NULL) {
		printf("Caractere 'd' encontrado na posição: %ld\n", resultado - data);
	} else {
		printf("Caractere 'd' não encontrado.\n");
	}

	return (0);
}*/
