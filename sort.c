#include "push_swap.h"
void sort_three(t_list **lst_a)
{
    if (!lst_a || !(*lst_a) || !(*lst_a)->next || !(*lst_a)->next->next)
        return;
    if ((*lst_a)->content > (*lst_a)->next->content 
        && (*lst_a)->content > (*lst_a)->next->next->content)
        ra(lst_a);
    if ((*lst_a)->next->content > (*lst_a)->content 
        && (*lst_a)->next->content > (*lst_a)->next->next->content)
        rra(lst_a);
    if ((*lst_a)->content > (*lst_a)->next->content)
        sa(lst_a);
}
void sort_stack(t_list **lst_a)
{
    int min_value;
    int idx_of_min_val;
    int median_a;
    
    min_value = find_min_val(*lst_a);
    idx_of_min_val = find_idx(*lst_a, min_value);
    median_a = get_list_size(*lst_a)/ 2;
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
void sort_more_than_three(t_list **lst_a, t_list **lst_b)
{
    if (get_list_size(*lst_a) > 3)
        pb(lst_a, lst_b);
    if (is_circularly_sorted(*lst_a))
        sort_stack(lst_a);
    if (get_list_size(*lst_a) > 3 && !is_sorted(*lst_a))
        pb(lst_a, lst_b);
    if (is_circularly_sorted(*lst_a))
        sort_stack(lst_a);
    while (get_list_size(*lst_a) >= 3 && !is_sorted(*lst_a))
	{
        set_cost(*lst_a, *lst_b);
        printf("CONTENT : %d\n", best_cost(*lst_a)->content);
        printf("RA : %d\n", best_cost(*lst_a)->ra);
        printf("RB : %d\n", best_cost(*lst_a)->rb);
        printf("RR : %d\n", best_cost(*lst_a)->rr);
        printf("RRA : %d\n", best_cost(*lst_a)->rra);
        printf("RRB : %d\n", best_cost(*lst_a)->rrb);
        printf("RRR : %d\n", best_cost(*lst_a)->rrr);
        move_best_to_top(lst_a, lst_b, best_cost(*lst_a));
        ft_display(*lst_a, *lst_b);
	}

}