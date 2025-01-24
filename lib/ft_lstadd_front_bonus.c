/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:54:20 by vfidelis          #+#    #+#             */
/*   Updated: 2024/10/15 13:23:53 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		new = *lst;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int main()
{
    char point[] = "ooooooooo";
    t_list *ola = {ft_lstnew(point)};
    t_list *hello = ft_lstnew("hello");
    ft_lstadd_front(&ola, hello);
    printf("%s", (char *)ola->content);

}*/
