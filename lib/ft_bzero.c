/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:55:46 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/12 17:55:54 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *string, size_t len)
{
	size_t	i;

	i = 0;
	while (i < (unsigned long int)len)
	{
		((unsigned char *)string)[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>
#include <string.h>

void	ft_bzero(void *string, size_t len); // Prototipo da sua funcao

void	test_bzero(size_t len) {
	// Aloca memória para um buffer
	char original[20];
	char custom[20];

	// Inicializa com dados diferentes
	strcpy(original, "Hello, World!");
	strcpy(custom, "Hello, World!");

	// Zera os buffers usando a função padrão e a sua
	bzero(original, len);
	ft_bzero(custom, len);

	// Exibe os resultados
	printf("Teste com len = %zu\n", len);
	printf("Original bzero: \"%s\"\n", original); 
		// Deve imprimir uma string vazia
	printf("Custom ft_bzero: \"%s\"\n", custom);  
		// Deve imprimir uma string vazia
	printf("\n");
}

int	main(void) {
	// Testes com diferentes comprimentos
	test_bzero(5);    // Deve zerar os primeiros 5 caracteres
	test_bzero(10);   // Deve zerar os primeiros 10 caracteres
	test_bzero(20);   // Deve zerar todos os caracteres disponíveis

	return (0);
}
*/
