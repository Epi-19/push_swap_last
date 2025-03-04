#include "push_swap.h"
int main(int argc, char **argv)
{
    t_list *lst_a;
	t_list *lst_b;
    //t_list *tmp;

	lst_b = NULL;
    lst_a = ft_pars(argc, argv);
    //if (!lst_a)
    //{
    //    printf("Erreur : Parsing invalide.\n");
    //    return (1);
    //}
    //printf("Liste chaînée après parsing :\n");
    //tmp = lst_a;
    //while (tmp)
    //{
    //    printf("%d -> ", tmp->content);
    //    tmp = tmp->next;
    //}
    //printf("NULL\n");
    if (!is_sorted(lst_a))
    {
        size_t size = get_list_size(lst_a);
        
        if (size == 2)
            sa(&lst_a);
        else if (size == 3)
            sort_three(&lst_a);
        else if (is_circularly_sorted(lst_a))
            sort_stack(&lst_a);
		else
			sort_more_than_three(&lst_a, &lst_b);
	}
	//printf("\nListe chaînée après tri/modifications :\n");
    //tmp = lst_a;
    //while (tmp)
    //{
    //    printf("%d -> ", tmp->content);
    //    tmp = tmp->next;
    //}
    //printf("NULL\n");
    ft_lstclear(&lst_a);
    return (0);
}
