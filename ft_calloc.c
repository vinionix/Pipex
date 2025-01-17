/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:22:33 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/24 11:19:09 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num != 0 && (num * size) / num != size)
		return (NULL);
	ptr = malloc(size * num);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}

/*
#include "libft.h"
#include <stdio.h>
#include <string.h>

// Função de teste para comparar ft_calloc e calloc
void	test_calloc(size_t num, size_t size) {
	// Usa a função original calloc para comparação
	void *original = calloc(num, size);
	void *custom = ft_calloc(num, size);

	// Verifica se a alocação foi bem-sucedida
	if (original && custom) {
		// Compara os resultados byte a byte
		if (memcmp(original, custom, num * size) == 0) {
			printf("Test Passed: ft
			_calloc and calloc returned identical memory for num =
				%zu, size = %zu\n", num, size);
		} else {
			printf("Test Failed: Memory differs for num = %zu, size = %zu\n",
				num, size);
		}
	} else if (!original && !custom) {
		printf("Both functions returned NULL: num = %zu, size = %zu\n", num,
			size);
	} else {
		printf("Mismatch in return (values: one returned NULL,
			the other did not for num = %zu, size = %zu\n", num, size));
	}

	// Libera a memória alocada
	free(original);
	free(custom);
}

int	main(void) {
	// Testes variados
	printf("Running tests...\n");
	test_calloc(5, sizeof(int));      // Teste com alocação para 5 inteiros
	test_calloc(10, sizeof(char));    // Teste com alocação para 10 caracteres
	test_calloc(21040400404040, sizeof(int));      // Teste com num = 0
	test_calloc(10, 0);                // Teste com size = 0
	test_calloc(1000, sizeof(double)); // Teste com alocação para 1000 doubles

	return (0);
}
*/