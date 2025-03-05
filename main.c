/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodebacq <rodebacq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:39:34 by rodebacq          #+#    #+#             */
/*   Updated: 2025/03/05 19:39:45 by rodebacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	size_t	size;

	lst_b = NULL;
	lst_a = ft_pars(argc, argv);
	if (!is_sorted(lst_a))
	{
		size = get_list_size(lst_a);
		if (size == 2)
			sa(&lst_a);
		else if (size == 3)
			sort_three(&lst_a);
		else
			sort_more_than_three(&lst_a, &lst_b);
	}
	ft_lstclear(&lst_a);
	return (0);
}

// if (!lst_a)
//{
//    printf("Erreur : Parsing invalide.\n");
//    return (1);
//}
// printf("Liste chaînée après parsing :\n");
// tmp = lst_a;
// while (tmp)
//{
//    printf("%d -> ", tmp->content);
//    tmp = tmp->next;
//}
// printf("NULL\n");

// printf("\nListe chaînée après tri/modifications :\n");
// tmp = lst_a;
// while (tmp)
//{
//    printf("%d -> ", tmp->content);
//    tmp = tmp->next;
//}
// printf("NULL\n");