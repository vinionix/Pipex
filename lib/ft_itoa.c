/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:43:38 by vfidelis          #+#    #+#             */
/*   Updated: 2024/10/01 12:43:41 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_int(long receptor)
{
	size_t	i;

	i = 0;
	if (receptor <= 0)
	{
		i = 1;
	}
	while (receptor != 0)
	{
		receptor /= 10;
		i++;
	}
	return (i);
}

static long	isnegative(long receptor, char *str)
{
	if (receptor < 0)
	{
		str[0] = '-';
		receptor = -receptor;
	}
	return (receptor);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	receptor;
	size_t	i;

	receptor = n;
	i = ft_len_int(receptor);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (receptor == 0)
	{
		str[0] = '0';
		return (str);
	}
	receptor = isnegative(receptor, str);
	while (receptor != 0)
	{
		str[--i] = (receptor % 10) + '0';
		receptor /= 10;
	}
	return (str);
}

/*int main()
{
	char *result = ft_itoa(12345);
	printf("%s\n", result);
	free(result);

	char *result1 = ft_itoa(-12345);
	printf("%s\n", result1);
	free(result1);

	char *result2 = ft_itoa(0);
	printf("%s\n", result2);
	free(result2);

	char *result3 = ft_itoa(-2147483648);
	printf("%s\n", result3);
	free(result3);
}*/