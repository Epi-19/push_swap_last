/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodebacq <rodebacq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:41:43 by rodebacq          #+#    #+#             */
/*   Updated: 2025/03/05 19:43:21 by rodebacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	if (!lst_b || !(*lst_b))
		return ;
	temp = *lst_b;
	*lst_b = (*lst_b)->next;
	temp->next = *lst_a;
	*lst_a = temp;
	write(1, "pa\n", 3);
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	if (!lst_a || !(*lst_a))
		return ;
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	temp->next = *lst_b;
	*lst_b = temp;
	write(1, "pb\n", 3);
}
