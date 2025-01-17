/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:04:35 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/24 14:08:41 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("%d", ft_isascii(-1));
	printf("%d", ft_isascii(0));
	printf("%d", ft_isascii(127));
	printf("%d", ft_isascii(128));
}*/
