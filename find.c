/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodebacq <rodebacq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:37:40 by rodebacq          #+#    #+#             */
/*   Updated: 2025/03/05 19:37:41 by rodebacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_max_node(t_list *lst_b)
{
	size_t	index;
	size_t	max_index;
	int		max_value;
	t_list	*tmp;

	index = 0;
	max_index = 0;
	max_value = lst_b->content;
	if (!lst_b)
		return (0);
	tmp = lst_b;
	while (tmp)
	{
		if (tmp->content > max_value)
		{
			max_value = tmp->content;
			max_index = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (max_index);
}

int	get_last_node(t_list *lst_b)
{
	while (lst_b->next)
		lst_b = lst_b->next;
	return (lst_b->content);
}

size_t	find_insert_position(t_list *lst_b, int value)
{
	size_t	index;
	int		prev;
	int		curr;
	t_list	*tmp;

	if (!lst_b)
		return (0);
	index = 0;
	prev = get_last_node(lst_b);
	tmp = lst_b;
	while (tmp)
	{
		curr = tmp->content;
		if (prev > value && curr < value)
			return (index);
		prev = curr;
		// if (tmp->content > value)
		//    return (index + 1);
		// if (tmp == max_node && value > lst_b->content)
		//    return (0);
		tmp = tmp->next;
		index++;
	}
	return (find_max_node(lst_b)); // + (value < prev);
}

int	find_min_val(t_list *lst)
{
	int		min_val;
	t_list	*tmp;

	min_val = lst->content;
	tmp = lst;
	while (tmp)
	{
		if (tmp->content < min_val)
			min_val = tmp->content;
		tmp = tmp->next;
	}
	return (min_val);
}

size_t	find_idx(t_list *lst, int value)
{
	size_t	index;
	t_list	*tmp;

	index = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->content == value)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (0);
}
