#include "push_swap.h"

int ra(t_list **lst_a)
{
    t_list *first;
    t_list *last;
    
    if (!lst_a || !(*lst_a) || !((*lst_a)->next))
        return 0;
    first = *lst_a;
	*lst_a = first->next;
    first->next = NULL;
    last = *lst_a;                
    while (last && last->next)
        last = last->next;
    last->next = first;
    write(1, "ra\n", 3);
    //ft_display(*lst_a, NULL);
	return 1;
}
int rb(t_list **lst_b)
{
    t_list *first;
    t_list *last;

    if (!lst_b || !(*lst_b) || !((*lst_b)->next))
        return 0;
    first = *lst_b;
    *lst_b = first->next;
    first->next = NULL;
    last = *lst_b;
    while (last && last->next)    
        last = last->next; 
    last->next = first;
    write(1, "rb\n", 3);
        //ft_display(NULL, *lst_b);
	return 1;
}
void lra(t_list **lst_a)
{
    t_list *first;
    t_list *last;
    
    if (!lst_a || !(*lst_a) || !((*lst_a)->next))
        return;
    first = *lst_a;
	*lst_a = first->next;
    first->next = NULL;
    last = *lst_a;                
    while (last && last->next)
        last = last->next;
    last->next = first;
}

void lrb(t_list **lst_b)
{
    t_list *first;
    t_list *last;

    if (!lst_b || !(*lst_b) || !((*lst_b)->next))
        return;
    first = *lst_b;
    *lst_b = first->next;
    first->next = NULL;
    last = *lst_b;
    while (last && last->next)    
        last = last->next;
    last->next = first;
}
int rr(t_list **lst_a, t_list **lst_b)
{
	if (!lst_a || !(*lst_a) || !(*lst_a)->next || !lst_b || !(*lst_b) || !(*lst_b)->next)
        return 0;
    lra(lst_a);
    lrb(lst_b);
    write(1, "rr\n", 3);
        //ft_display(*lst_a, *lst_b);
	return 1;
}