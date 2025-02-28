#include "push_swap.h"

void pa(t_list **lst_a, t_list **lst_b)
{
    t_list *temp;

    if (!lst_b || !(*lst_b))
        return;
    temp = *lst_b;
    *lst_b = (*lst_b)->next;
    temp->next = *lst_a;
    *lst_a = temp;
    write(1, "pa\n", 3);
        //ft_display(*lst_a, *lst_b);
}
void pb(t_list **lst_a, t_list **lst_b)
{
    t_list *temp;

    if (!lst_a || !(*lst_a))  
        return;
    temp = *lst_a;
    *lst_a = (*lst_a)->next;
    temp->next = *lst_b;
    *lst_b = temp;
    write(1, "pb\n", 3);
    //ft_display(*lst_a, *lst_b);
}