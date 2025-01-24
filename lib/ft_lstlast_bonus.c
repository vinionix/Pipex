/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:24:44 by vfidelis          #+#    #+#             */
/*   Updated: 2024/10/15 13:24:55 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*int main()
{
    t_list *lststart;
    t_list *lstbody;
    t_list *lstend;

    lststart = malloc (sizeof(t_list));
    lstbody = malloc (sizeof(t_list));
    lstend = malloc (sizeof(t_list));

    if (!lststart || !lstend || !lstbody)
        return (1);
    lststart -> next = lstbody;
    lstbody -> next = lstend;
    lstend -> next = NULL;

    ft_lstlast(lststart);
}*/
