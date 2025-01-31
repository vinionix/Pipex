/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:09:39 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/30 22:54:28 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*receptor;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	receptor = (char *)malloc(sizeof(char) * (len + 2));
	while (s1[++i] != '\0')
		receptor[i] = s1[i];
	if (s2[j] != '/')
		receptor[i++] = '/';
	while (s2[j] != '\0')
	{
		receptor[i++] = s2[j++];
		if (s2[j] == ' ')
			break ;
	}
	receptor[i] = '\0';
	return (receptor);
}