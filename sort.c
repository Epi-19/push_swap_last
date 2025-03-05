/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodebacq <rodebacq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:47:08 by rodebacq          #+#    #+#             */
/*   Updated: 2025/03/05 19:47:29 by rodebacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst_a)
{
	if (!lst_a || !(*lst_a) || !(*lst_a)->next || !(*lst_a)->next->next)
		return ;
	if ((*lst_a)->content > (*lst_a)->next->content
		&& (*lst_a)->content > (*lst_a)->next->next->content)
		ra(lst_a);
	if ((*lst_a)->next->content > (*lst_a)->content
		&& (*lst_a)->next->content > (*lst_a)->next->next->content)
		rra(lst_a);
	if ((*lst_a)->content > (*lst_a)->next->content)
		sa(lst_a);
}

void	sort_stack(t_list **lst_a)
{
	int	min_value;
	int	idx_of_min_val;
	int	median_a;

	min_value = find_min_val(*lst_a);
	idx_of_min_val = find_idx(*lst_a, min_value);
	median_a = get_list_size(*lst_a) / 2;
	if (get_list_size(*lst_a) % 2 == 1)
		median_a += 1;
	if (idx_of_min_val < median_a)
	{
		while (*lst_a && (*lst_a)->content != min_value)
			ra(lst_a);
	}
	else
	{
		while (*lst_a && (*lst_a)->content != min_value)
			rra(lst_a);
	}
}

int	find_max_value(t_list *lst)
{
	int	max_value;

	max_value = lst->content;
	while (lst)
	{
		if (lst->content > max_value)
			max_value = lst->content;
		lst = lst->next;
	}
	return (max_value);
}

void	rotate_to_top(t_list **lst_b)
{
	int	max_value;
	int	size;
	int	pos;
	int	xrb;
	int	xrrb;

	max_value = find_max_value(*lst_b);
	size = get_list_size(*lst_b);
	pos = find_idx(*lst_b, max_value);
	xrb = pos;
	xrrb = (size - pos) % size;
	if (xrb <= xrrb)
	{
		while (xrb > 0)
			xrb -= rb(lst_b);
	}
	else
	{
		while (xrrb > 0)
			xrrb -= rrb(lst_b);
	}
}

int	get_insert_position(t_list *lst_a, int value)
{
	size_t	index;
	t_list	*tmp;

	index = 0;
	tmp = lst_a;
	if (!lst_a || value < lst_a->content)
		return (0);
	while (tmp->next)
	{
		if (tmp->content <= value && tmp->next->content > value)
			return (index + 1);
		tmp = tmp->next;
		index++;
	}
	return (index + 1);
}

void	move_min_to_top(t_list **lst)
{
	int	size;
	int	min_index;

	size = get_list_size(*lst);
	min_index = find_idx((*lst), find_min_val(*lst));
	if (min_index == -1 || size < 2)
		return ;
	if (min_index <= size / 2)
	{
		while (min_index--)
			ra(lst);
	}
	else
	{
		min_index = size - min_index;
		while (min_index--)
			rra(lst);
	}
}

void	sort_more_than_three(t_list **lst_a, t_list **lst_b)
{
	if (get_list_size(*lst_a) == 5)
	{
		move_min_to_top(lst_a);
		pb(lst_a, lst_b);
		move_min_to_top(lst_a);
		pb(lst_a, lst_b);
		sort_three(lst_a);
		while (*lst_b)
			pa(lst_a, lst_b);
		return ;
	}
	pb(lst_a, lst_b);
	pb(lst_a, lst_b);
	while (get_list_size(*lst_a) > 0)
	{
		set_cost(*lst_a, *lst_b);
		move_best_to_top(lst_a, lst_b, best_cost(*lst_a));
	}
	rotate_to_top(lst_b);
	while (*lst_b)
		pa(lst_a, lst_b);
}
