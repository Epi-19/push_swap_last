#include "push_swap.h"

void sa(t_list **lst_a)
{
    t_list *first;
    t_list *second;

    if (!lst_a || !(*lst_a) || !((*lst_a)->next))
        return;
    first = *lst_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *lst_a = second;
	write(1, "sa\n", 3);
}

void sb(t_list **lst_b)
{
	t_list *first;
    t_list *second;

    if (!lst_b || !(*lst_b) || !((*lst_b)->next))
        return;
    first = *lst_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *lst_b = second;
	write(1, "sb\n", 3);
}

void ss(t_list **lst_a, t_list **lst_b)
{
    t_list *first_a;
    t_list *second_a;
    t_list *first_b;
    t_list *second_b;

    if (lst_a && *lst_a && (*lst_a)->next)
    {
        first_a = *lst_a;
        second_a = first_a->next;
        first_a->next = second_a->next;
        second_a->next = first_a;
        *lst_a = second_a;
    }
    if (lst_b && *lst_b && (*lst_b)->next)
    {
        first_b = *lst_b;
        second_b = first_b->next;
        first_b->next = second_b->next;
        second_b->next = first_b;
        *lst_b = second_b;
    }
    write(1, "ss\n", 3);
}