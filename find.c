#include "push_swap.h"

size_t find_max_node(t_list *lst_b, t_list **max_node)
{
    size_t index;
    size_t max_index;
    *max_node = lst_b;

    index = 0;
    max_index = 0;
    *max_node = lst_b;
    if (!lst_b)
        return 0;

    t_list *tmp = lst_b;
    while (tmp)
    {
        if (tmp->content > (*max_node)->content)
        {
            *max_node = tmp;
            max_index = index;
        }
        tmp = tmp->next;
        index++;
    }
    return max_index;
}

size_t find_insert_position(t_list *lst_b, int value)
{
    size_t index;
    //size_t max_index;
    t_list *tmp;
    t_list *max_node;

    index = 0;
    find_max_node(lst_b, &max_node);
    tmp = lst_b;
    if (!lst_b)
        return 0;
    tmp = lst_b;
    index = 0;
    while (tmp)
    {
        if (tmp->content > value)
            return index + 1;
        if (tmp == max_node && value > lst_b->content)
            return 0;
        tmp = tmp->next;
        index++;
    }
    return index;
}
int find_min_val(t_list *lst)
{
    int min_val = lst->content;
    t_list *tmp = lst;
    while (tmp)
    {
        if (tmp->content < min_val)
            min_val = tmp->content;
        tmp = tmp->next;
    }
    return min_val;
}
size_t find_idx(t_list *lst, int value)
{
    size_t index;
    t_list *tmp;

    index = 0;
    tmp = lst;
    while (tmp)
    {
        if (tmp->content == value)
            return index;
        tmp = tmp->next;
        index++;
    }
    return 0;
}



