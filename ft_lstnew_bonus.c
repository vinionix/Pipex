/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:28:11 by vfidelis          #+#    #+#             */
/*   Updated: 2024/10/08 17:28:13 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

/*#include <stdio.h> // Para printf
#include "libft.h"  // Inclua a função e a struct da lista
#include <stdlib.h> // Para malloc

int	main(void)
{
    // Cria um conteúdo para o nó da lista
    char *content = "Hello, world!";
    
    // Cria um novo nó usando ft_lstnew
    t_list *node = ft_lstnew(content);

    // Verifica se o nó foi criado corretamente
    if (node)
    {
        printf("Content: %s\n", (char *)node->content);
        printf("Next: %p\n", (void *)node->next); // Deve ser NULL
    }
    else
    {
        printf("Erro ao criar o nó!\n");
    }

    // Libera a memória alocada para evitar vazamento de memória
    free(node);

    return (0);
}*/
