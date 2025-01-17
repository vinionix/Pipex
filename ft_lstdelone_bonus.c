/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:24:19 by vfidelis          #+#    #+#             */
/*   Updated: 2024/10/15 13:24:32 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}

/*void delete(void *lst)
{
   free((t_list *)lst);
}
int	main(void)
{
    t_list *lststart;
    t_list *lstbody;
    t_list *lstend;

    lststart = malloc (sizeof(t_list));
    lstbody = malloc (sizeof(t_list));
    lstend = malloc (sizeof(t_list));

    if (!lststart || !lstend || !lstbody)
        return (1);

    lststart -> content = ft_strdup("Boa dia");
    lststart -> next = lstbody;

    lstbody -> content = ft_strdup("Boa tarde");
    lstbody -> next = lstend;

    lstend -> content = ft_strdup("Boa noite");
    lstend -> next = NULL;

    printf ("%s\n", (char *)lststart -> next -> content);
    ft_lstdelone(lststart, delete);
    printf ("%s\n", (char *)lstbody -> content);
    printf ("%s\n", (char *)lstbody -> next -> content);
}*/
