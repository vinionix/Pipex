/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:50:26 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/24 13:59:11 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d", ft_isalnum('a'));
	printf("%d", ft_isalnum('A'));
	printf("%d", ft_isalnum('0'));
	printf("%d", ft_isalnum(0));
}*/
