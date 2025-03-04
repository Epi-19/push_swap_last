#include "push_swap.h"

static int max(int a, int b) { return a > b ? a : b; }
static int min(int a, int b) { return a < b ? a : b; }

void ft_optimize(t_list *lst)
{
    // ra + rb -> rr
    // ra + rrb -> rine
    // rra + rb -> rine
    // rra + rrb -> rrr

    //if (lst->content == 12) {
    //    printf("ra: %d\n", lst->ra);
    //    printf("rb: %d\n", lst->rb);
    //    printf("rra: %d\n", lst->rra);
    //    printf("rrb: %d\n", lst->rrb);
    //    printf("rr: %d\n", lst->rr);
    //}
    if (max(lst->ra, lst->rb) < max(lst->rra, lst->rrb))
    {
        if (max(lst->ra, lst->rb) > (lst->ra + lst->rrb))
            return ;
        if (max(lst->ra, lst->rb) > (lst->rra + lst->rb))
            return ;
        lst->rr = min(lst->ra, lst->rb);
        //printf("rr apres le calcul: %d\n", lst->rr);
        lst->ra -= lst->rr;
        lst->rb -= lst->rr;
    }
    else
    {
        if (max(lst->rra, lst->rrb) > (lst->ra + lst->rrb))
            return ;
        if (max(lst->rra, lst->rrb) > (lst->rra + lst->rb))
            return ;
        lst->rrr = min(lst->rra, lst->rrb);
        lst->rra -= lst->rrr;
        lst->rrb -= lst->rrr;
    }
    //if (lst->content == 12) {
    //    printf("ra: %d\n", lst->ra);
    //    printf("rb: %d\n", lst->rb);
    //    printf("rra: %d\n", lst->rra);
    //    printf("rrb: %d\n", lst->rrb);
    //    printf("rr: %d\n", lst->rr);
    //    printf("rrr: %d\n", lst->rrr);
    //}
}

void set_cost(t_list *lst_a, t_list *lst_b)
{
    t_list *tmp_a;
    int size_a;
    int size_b;

    size_a = get_list_size(lst_a);
    size_b = get_list_size(lst_b);
    tmp_a = lst_a;
    while (tmp_a)
    {
        tmp_a->rr = 0;
        tmp_a->rrr = 0;
        //ft_bzero(tmp_a, sizeof(t_list));
        //tmp_a->ra = 0;
        //tmp_a->rra = 0;
        //tmp_a->rb = 0;
        //tmp_a->rrb = 0;
        tmp_a->ra = find_idx(lst_a, tmp_a->content);
        tmp_a->rra = (size_a - tmp_a->ra) % size_a;
        tmp_a->rb = find_insert_position(lst_b, tmp_a->content);
        tmp_a->rrb = (size_b - tmp_a->rb) % size_b;

        ft_optimize(tmp_a);

        //if (max(tmp_a->ra, tmp_a->rb) > max(tmp_a->rra, tmp_a->rrb)) {
        //    if (max(tmp_a->ra, tmp_a->rb) < min(tmp_a->ra + tmp_a->rrb, tmp_a->rb + tmp_a->rra))
        //        opti_cost_rr(tmp_a);
        //} else {
        //    if (max(tmp_a->rra, tmp_a->rrb) < min(tmp_a->ra + tmp_a->rrb, tmp_a->rb + tmp_a->rra))
        //        opti_cost_rrr(tmp_a);
        //}

        //if (max(tmp_a->ra, tmp_a->rb) > max(tmp_a->rra, tmp_a->rrb)) {
        //    if (max(tmp_a->ra, tmp_a->rb) < min(tmp_a->ra + tmp_a->rrb, tmp_a->rb + tmp_a->rra))
        //        opti_cost_rrr(tmp_a);
        //} else {
        //    if (max(tmp_a->rra, tmp_a->rrb) < min(tmp_a->ra + tmp_a->rrb, tmp_a->rb + tmp_a->rra))
        //        opti_cost_rr(tmp_a);
        //}
// ra: 4
// rb: 10
// rra: 7
// rrb: 8

// rr: 4
// rb: 6

        //printf("ra ; %d\n", tmp_a->ra);
        //printf("rb ; %d\n", tmp_a->rb);
        //printf("rra ; %d\n", tmp_a->rra);
        //printf("rrb ; %d\n", tmp_a->rrb);
        tmp_a = tmp_a->next;
    }
    //printf("rr apres le calcul: %d\n", tmp_a->rr);
	//opti_cost_rr(lst_a);
    //opti_cost_rrr(lst_a); 
}
void opti_cost_rr(t_list *tmp_a)
{
    //t_list *tmp_a;

    //tmp_a = a;
    //while (tmp_a)
    //{
        //if (tmp_a->ra > tmp_a->rb)
        //{
        //    tmp_a->rr = tmp_a->rb;
        //    tmp_a->ra -= tmp_a->rr;
        //    tmp_a->rb = 0;
        //}
        //else if (tmp_a->ra < tmp_a->rb)
        //{
        //    tmp_a->rr = tmp_a->ra;
        //    tmp_a->rb -= tmp_a->rr;
        //    tmp_a->ra = 0;
        //}
        //else {
        //    tmp_a->rr = tmp_a->ra;
        //    tmp_a->ra = 0;
        //    tmp_a->rb = 0;
        //}
        while (tmp_a->ra != 0 && tmp_a->rb != 0)
        {
            tmp_a->ra--;
            tmp_a->rb--;
            tmp_a->rr++;
        }
        tmp_a->rra = 0;
        tmp_a->rrb = 0;
        //tmp_a = tmp_a->next;
    //}
}
void opti_cost_rrr(t_list *tmp_a)
{
    //t_list *tmp_a;

    //tmp_a = a;
    //while (tmp_a)
    //{
        //if (tmp_a->rra > tmp_a->rrb)
        //{
        //    tmp_a->rrr = tmp_a->rrb;
        //    tmp_a->rra -= tmp_a->rrr;
        //    tmp_a->rrb = 0;
        //}
        //else if (tmp_a->rra < tmp_a->rrb)
        //{
        //    tmp_a->rrr = tmp_a->rra;
        //    tmp_a->rrb -= tmp_a->rrr;
        //    tmp_a->rra = 0;
        //}
        //else {
        //    tmp_a->rrr = tmp_a->rra;
        //    tmp_a->rra = 0;
        //    tmp_a->rrb = 0;
        //}
        while (tmp_a->rra != 0 && tmp_a->rrb != 0)
        {
            tmp_a->rra--;
            tmp_a->rrb--;
            tmp_a->rrr++;
        }
        tmp_a->ra = 0;
        tmp_a->rb = 0;
        //tmp_a = tmp_a->next;
    //}
}
//t_list *best_cost(t_list *lst_a)
//{
//    t_list *best_node = lst_a;
//    t_list *current = lst_a;
//    int min_cost = INT_MAX;
//    int total_cost;

//    while (current)
//    {
//        total_cost = 0;

//        // Choisir le coût minimum entre ra et rra
//        if (current->ra < current->rra)
//            total_cost += current->ra;
//        else
//            total_cost += current->rra;

//        // Choisir le coût minimum entre rb et rrb
//        if (current->rb < current->rrb)
//            total_cost += current->rb;
//        else
//            total_cost += current->rrb;

//        // Choisir le coût minimum entre rr et rrr
//        if (current->rr < current->rrr)
//            total_cost += current->rr;
//        else
//            total_cost += current->rrr;

//        // Mise à jour du meilleur nœud si on a trouvé un coût plus bas
//        if (total_cost < min_cost)
//        {
//            min_cost = total_cost;
//            best_node = current;
//        }

//        current = current->next;
//    }
//    return best_node;
//}

t_list *best_cost(t_list *lst_a)
{
    t_list *best_node;
    t_list *current;
    int min_cost;
    int total_cost;

    best_node = lst_a;
    current = lst_a;
    min_cost = INT_MAX;
    while (current)
    {
        total_cost = ft_comp(current->ra, current->rra) + current->rr +
                        ft_comp(current->rb, current->rrb) + current->rrr;
        // printf("TOTAL COST : %d\n", total_cost);
//printf("costs:\n");
//printf("%d: ra %d rb %d rra %d rrb %d\n", current->content, current->ra, current->rb, current->rra, current->rrb);
        if (total_cost < min_cost)
        {
            min_cost = total_cost;
            best_node = current;
        }
        current = current->next;
    }
    return best_node;
}
int ft_comp(int i, int j)
{
    if(i < j)
        return (i);
    return (j);
}


