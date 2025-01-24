/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:42:29 by vfidelis          #+#    #+#             */
/*   Updated: 2024/10/07 11:42:32 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*void ft_função (unsigned int i, char *letter)
{
	i = 0;
	if (*letter >= 'a' && *letter <= 'z')
	{
		*letter = *letter - 32;
	}
}

int	main(void)
{
	char str[] = "Ola";
	ft_striteri(str, ft_função);
	printf("%s", str);
}*/