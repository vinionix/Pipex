/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:19:44 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/19 18:19:47 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			i;
	unsigned char	*ptr1copy;
	unsigned char	*ptr2copy;

	ptr1copy = (unsigned char *)ptr1;
	ptr2copy = (unsigned char *)ptr2;
	i = 0;
	while (i < num)
	{
		if (ptr1copy[i] > ptr2copy[i] || ptr1copy[i] < ptr2copy[i])
			return (ptr1copy[i] - ptr2copy[i]);
		i++;
	}
	return (0);
}

/*int main() {
	char str1[] = "abcdez";
	char str2[] = "abcdea";
	int result;

	// Compara os primeiros 6 bytes de str1 e str2
	result = ft_memcmp(str1, str2, 6);
	if (result == 0)
	{
		printf("Os blocos de memória são iguais.\n");
	}
	else if (result < 0)
	{
		printf("str1 é menor que str2.\n");
	}
	else
	{
		printf("str1 é maior que str2.\n");
	}

	return (0);
}*/
