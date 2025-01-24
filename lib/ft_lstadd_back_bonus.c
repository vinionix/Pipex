/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:23:06 by vfidelis          #+#    #+#             */
/*   Updated: 2024/10/15 13:23:20 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*receptor;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	receptor = *lst;
	while (receptor->next != NULL)
		receptor = receptor->next;
	receptor->next = new;
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
    lststart -> content = "abcde";
    lststart -> next = NULL;
    lstbody -> next = lstend;
    lstend -> next = lststart;

    printf ("%s", (char *)lststart -> next);
    ft_lstadd_back(&lststart, lstend);
    printf ("%s", (char *)lststart -> next);
}*/
