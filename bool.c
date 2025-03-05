/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodebacq <rodebacq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:30:20 by rodebacq          #+#    #+#             */
/*   Updated: 2025/03/05 19:30:21 by rodebacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *lst_a)
{
	while (lst_a && lst_a->next)
	{
		if (lst_a->content > lst_a->next->content)
			return (false);
		lst_a = lst_a->next;
	}
	return (true);
}

//t_list *find_min_node(t_list *lst_a)
//{
//    t_list *min_node;
//    t_list *current;

//    min_node = lst_a;
//    current = lst_a->next;
//    while (current)
//    {
//        if (current->content < min_node->content)
//            min_node = current;
//        current = current->next;
//    }
//    return min_node;
//}
