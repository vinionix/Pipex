/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:57:04 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/18 11:57:13 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	space(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = space(str);
	sign = 1;
	num = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(num * sign));
}

/*#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str); // Prototipo da sua funcao

void	test_atoi(const char *test_case) {
	int original_result = atoi(test_case);
	int custom_result = ft_atoi(test_case);

	printf("Entrada: \"%s\" -> Original: %d, Custom: %d\n", test_case,
		original_result, custom_result);
}

int	main(void) {
	// Casos de teste
	test_atoi("-+123");              // 123
	test_atoi("-456");             // -456
	test_atoi("+789");             // 789
	test_atoi("   42");            // 42
	test_atoi("-   32");           // -32
	test_atoi("   +123   ");       // 123
	test_atoi("abc123");           // 0
	test_atoi("   -123abc");       // -123
	test_atoi("12ab34");           // 12
	test_atoi("21474836470");       // 2147483647
	test_atoi("2147483648");       // 2147483647 (ou erro)
	test_atoi("-2147483648");      // -2147483648
	test_atoi("-2147483649");      // -2147483648 (ou erro)
	test_atoi("0000123");          // 123
	test_atoi("-0000123");         // -123
	test_atoi("0");                // 0
	test_atoi("");                 // 0
	test_atoi("   ");              // 0
	test_atoi("abc");              // 0
	test_atoi("--123");            // 0 (ou erro)

	return (0);
}
*/
