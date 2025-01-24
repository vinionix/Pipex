/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:37:33 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/15 19:36:25 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src || n == 0)
	{
		return (dest);
	}
	if ((unsigned char *)dest < (unsigned char *)src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		}
	}
	return (dest);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

void	print_test_result(const char *test_case, char *dest1, char *dest2,
		int n) {
	printf("Test: %s\n", test_case);
	printf("ft_memmove result: %s\n", dest1);
	printf("memmove result: %s\n", dest2);
	if (strcmp(dest1, dest2) == 0) {
		printf("Result: PASS\n\n");
	} else {
		printf("Result: FAIL\n\n");
	}
}

int	main(void)
{
	char	src1[];
	char	dest1[20];
	char	dest2[20];
	char	overlap_src1[];
	char	overlap_dest1[];
	char	zero_src[];
	char	zero_dest1[20];
	char	zero_dest2[20];
	char	identical_src[];
	char	identical_dest[20];

	src1[] = "Hello, World!";
	overlap_src1[] = "123456789";
	overlap_dest1[] = "Hello, World!";
	zero_src[] = "Test";
	zero_dest1[20] = "Before";
	zero_dest2[20] = "Before";
	identical_src[] = "Identical";
	identical_dest[20] = "Identical";
	// Test 1: Normal copy
	ft_memmove(dest1, src1, 13);
	memmove(dest2, src1, 13);
	print_test_result("Normal copy", dest1, dest2, 13);
	// Test 2: Overlapping regions (dest before src)
	char overlap_src2[] = "123456789"; // Copy original to compare later
	ft_memmove(overlap_src1 + 2, overlap_src1, 5); // "12345" para "34567"
	memmove(overlap_src2 + 2, overlap_src2, 5); // "12345" para "34567"
	print_test_result("Overlap (dest before src)", overlap_src1, overlap_src2,
		5);
	// Test 3: Overlapping regions (dest after src)
	char overlap_dest2[] = "Hello, World!"; // Copy original to compare later
	ft_memmove(overlap_dest1 + 5, overlap_dest1, 7); // "Hello, " para "Hello,
		Hello, "
	memmove(overlap_dest2 + 5, overlap_dest2, 7); // "Hello, " para "Hello,
		Hello, "
	print_test_result("Overlap (dest after src)", overlap_dest1, overlap_dest2,
		7);
	// Test 4: Zero length copy
	ft_memmove(zero_dest1, zero_src, 0); // No copy
	memmove(zero_dest2, zero_src, 0); // No copy
	print_test_result("Zero length copy", zero_dest1, zero_dest2, 0);
	// Test 5: Identical src and dest
	ft_memmove(identical_dest, identical_src, 10); // Same src and dest
	memmove(identical_dest, identical_src, 10); // Same src and dest
	print_test_result("Identical src and dest", identical_dest, identical_dest,
		10);
	return (0);
}
*/