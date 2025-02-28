#include "push_swap.h"

int rra(t_list **lst_a)
{
    t_list *last;
    t_list *before_last;

    if (!lst_a || !(*lst_a) || !(*lst_a)->next)
        return 0;
    last = *lst_a;
    before_last = NULL;
    while (last->next)
    {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *lst_a;
    *lst_a = last;
    write(1, "rra\n", 4);
	return 1;
        //ft_display(*lst_a, NULL);
}
int rrb(t_list **lst_b)
{
    t_list *last;
    t_list *before_last;

    if (!lst_b || !(*lst_b) || !(*lst_b)->next)
        return 0;
    last = *lst_b;
    before_last = NULL;
    while (last->next)
    {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *lst_b;
    *lst_b = last;
    write(1, "rrb\n", 4);
	return 1;
        //ft_display(NULL, *lst_b);
}
void lrra(t_list **lst_a)
{
    t_list *last;
    t_list *before_last;

    if (!lst_a || !(*lst_a) || !(*lst_a)->next)
        return;
    last = *lst_a;
    before_last = NULL;
    while (last->next)
    {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *lst_a;
    *lst_a = last;
}

void lrrb(t_list **lst_b)
{
    t_list *last;
    t_list *before_last;

    if (!lst_b || !(*lst_b) || !(*lst_b)->next)
        return;
    last = *lst_b;
    before_last = NULL;
    while (last->next)
    {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *lst_b;
    *lst_b = last;
}

int rrr(t_list **lst_a, t_list **lst_b)
{
    if ((!lst_a || !(*lst_a) || !(*lst_a)->next) || (!lst_b || !(*lst_b) || !(*lst_b)->next))
        return 0;
    lrra(lst_a);
    lrrb(lst_b);
    write(1, "rrr\n", 4);
    //ft_display(*lst_a, *lst_b);
	return 1;
}