/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:40:55 by vfidelis          #+#    #+#             */
/*   Updated: 2024/10/05 14:40:57 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	endline(const char *str, const char *set)
{
	size_t	endl;

	endl = ft_strlen(str);
	while (endl > 0 && ft_strchr(set, str[endl - 1]))
		endl--;
	return (endl);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*s1copy;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = endline(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	s1copy = (char *)malloc(sizeof(char) * (end - start + 1));
	if (s1copy == NULL)
		return (NULL);
	ft_memcpy(s1copy, &s1[start], end - start);
	s1copy[end - start] = '\0';
	return (s1copy);
}

/*int main()
 {
	char    str[] = "abcdefg";
	char    set[] = "cdavf";
	char *receptor = ft_strtrim(str, set);

	printf ("%s", receptor);
 }*/
