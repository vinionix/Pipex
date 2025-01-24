/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:06:10 by vfidelis          #+#    #+#             */
/*   Updated: 2025/01/15 16:31:14 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	word_count;
	size_t	in_word;

	word_count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			word_count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (word_count);
}

static void	*ft_free_memory(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	**body(char **res, const char *s, char c, size_t word_count)
{
	size_t	i;
	size_t	h;
	size_t	wl;

	i = 0;
	h = 0;
	wl = 0;
	while (s[h] && i < word_count)
	{
		if (s[h] != c)
			wl++;
		if ((s[h] == c || s[h + 1] == '\0') && wl > 0)
		{
			res[i] = (char *)malloc(wl + 1);
			if (!res[i])
				return (ft_free_memory(res, i));
			ft_memcpy(res[i], &s[h - wl + (s[h + 1] == '\0' && s[h] != c)], wl);
			res[i][wl] = '\0';
			i++;
			wl = 0;
		}
		h++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	result[word_count] = NULL;
	return (body(result, s, c, word_count));
}
