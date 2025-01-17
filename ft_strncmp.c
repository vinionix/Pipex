/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:27:23 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/30 12:27:25 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*int main()
{
	char    arr1[] = "42";
	char    arr2[] = "42 Rio";
	size_t  i = 10;
	int result = ft_strncmp(arr1, arr2, i);

	if (result > 0)
		printf("arr1 é maior: %d", result);
	else if (result < 0)
		printf("arr1 é menor: %d", result);
	printf("Strings iguais: %d", result);
}*/