/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:27:23 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/30 12:27:25 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_need_le;

	len_need_le = ft_strlen(needle);
	if (len_need_le == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] && i + len_need_le <= len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], needle, len_need_le) == 0)
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
	printf("%s", ft_strnstr("Hello, World!", "World", 13));
	printf("%s", ft_strnstr(NULL, "World", 10));
	printf("%s", ft_strnstr("Hello, World!", "World", 0));
	printf("%s", ft_strnstr("Hello, World!", "", 10));
}*/