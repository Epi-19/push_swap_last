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

t_list *find_min_node(t_list *lst_a)
{
    t_list *min_node;
    t_list *current;

    min_node = lst_a;
    current = lst_a->next;
    while (current)
    {
        if (current->content < min_node->content)
            min_node = current;
        current = current->next;
    }
    return min_node;
}

bool is_sorted_from(t_list *start, int size)
{
    t_list *current;
    t_list *next_node;
    int i = 0;

    current = start;
    while (i < size - 1)
    {
        if (current->next != NULL)
            next_node = current->next;
        else
            next_node = start;

        if (next_node->content < current->content)
            return false;

        current = next_node;
        i++;
    }
    return true;
}

bool is_circularly_sorted(t_list *lst_a)
{
    t_list *min_node;
    t_list *current;
    int size_a;

    if (!lst_a || !lst_a->next)
        return true;
    min_node = find_min_node(lst_a);
    size_a = get_list_size(lst_a);
    if (!is_sorted_from(min_node, size_a))
        return false;
    current = lst_a;
    while (current->next != min_node)
    {
        if (current->content < min_node->content)
            return false;
        current = current->next;
    }
    return true;
}
