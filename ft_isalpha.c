/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:35:43 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/24 12:48:38 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d", ft_isalpha('a'));
	printf("%d", ft_isalpha('z'));
	printf("%d", ft_isalpha('A'));
	printf("%d", ft_isalpha('Z'));
	printf("%d", ft_isalpha(0));
}*/
