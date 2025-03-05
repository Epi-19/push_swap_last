/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodebacq <rodebacq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:45:44 by rodebacq          #+#    #+#             */
/*   Updated: 2025/03/05 19:46:33 by rodebacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_rrr(t_list *best_node)
{
	if (best_node->rr < best_node->rrr)
		best_node->rrr = 0;
	else
		best_node->rr = 0;
}

void	ra_rra(t_list *best_node)
{
	if (best_node->ra < best_node->rra)
		best_node->rra = 0;
	else
		best_node->ra = 0;
}

void	rb_rrb(t_list *best_node)
{
	if (best_node->rb < best_node->rrb)
		best_node->rrb = 0;
	else
		best_node->rb = 0;
}

	// rr_rrr(best_node); verrrrrrrrrrrrrrrrrrrrrrrrrifffffff
void	move_best_to_top(t_list **lst_a, t_list **lst_b, t_list *best_node)
{
	if (!lst_a || !lst_b || !best_node)
		return ;
	ra_rra(best_node);
	rb_rrb(best_node);
	while (best_node->rr > 0)
		best_node->rr -= rr(lst_a, lst_b);
	while (best_node->rrr > 0)
		best_node->rrr -= rrr(lst_a, lst_b);
	while (best_node->ra > 0)
		best_node->ra -= ra(lst_a);
	while (best_node->rra > 0)
		best_node->rra -= rra(lst_a);
	while (best_node->rb > 0)
		best_node->rb -= rb(lst_b);
	while (best_node->rrb > 0)
		best_node->rrb -= rrb(lst_b);
	pb(lst_a, lst_b);
}

// void ft_display(t_list *lst_a, t_list *lst_b)
//{
//    t_list *tmp_a = lst_a;
//    t_list *tmp_b = lst_b;

//    printf("---- STACK A ----    ---- STACK B ----\n");
//    while (tmp_a || tmp_b)
//    {
//        if (tmp_a)
//        {
//            printf("%-17d", tmp_a->content);
//            tmp_a = tmp_a->next;
//        }
//        else
//            printf("%-17s", " ");

//        if (tmp_b)
//        {
//            printf("%d", tmp_b->content);
//            tmp_b = tmp_b->next;
//        }

//        printf("\n");
//    }
//    printf("----------------    ----------------\n");
//}
