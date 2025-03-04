#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int 			ra;
	int				rb;
	int				rr;
	int 			rra;
	int				rrb;
	int				rrr;
	
	struct s_list	*next;
}	t_list;

//				BOOL.C
bool	is_sorted(t_list *lst_a);
t_list *find_min_node(t_list *lst_a);
bool is_sorted_from(t_list *start, int size);
bool is_circularly_sorted(t_list *lst_a);
//				CALLOC.C
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t all, size_t size);
//				COST.C
void set_cost(t_list *lst_a, t_list *lst_b);
void opti_cost_rr(t_list *a);
void opti_cost_rrr(t_list *a);
t_list *best_cost(t_list *lst_a);
int ft_comp(int i, int j);
//				FIND.C
size_t find_max_node(t_list *lst_b);
size_t find_insert_position(t_list *lst_b, int value);
size_t find_idx(t_list *lst, int value);
int find_min_val(t_list *lst);
//				LST.C
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstclear(t_list **lst);
t_list *ft_lstnew(int content);
t_list *ft_lstlast(t_list *lst);
int get_list_size(t_list *lst);
//				MAIN.C
int main(int argc, char **argv);
//				PARSING_1.C
void ft_error();
int ft_sign(const char *str, int *i);
int	ft_is_valid_number(const char *str);
long int ft_atoi_sec(const char *str);
int	ft_is_duplicate(t_list *list, int num);
//				PARSING_2.C
t_list	*ft_ac_2(char **av);
t_list	*ft_pars(int ac, char **av);
//				PUSH.C			
void pa(t_list **lst_a, t_list **lst_b);
void pb(t_list **lst_a, t_list **lst_b);
//				REV_ROT.C
int rra(t_list **lst_a);
int rrb(t_list **lst_b);
void lrra(t_list **lst_a);
void lrrb(t_list **lst_b);
int rrr(t_list **lst_a, t_list **lst_b);
//				ROT.C
int ra(t_list **lst_a);
int rb(t_list **lst_b);
void lra(t_list **lst_a);
void lrb(t_list **lst_b);
int rr(t_list **lst_a, t_list **lst_b);
//				SORT_UTILS.C
void move_best_to_top(t_list **lst_a, t_list **lst_b, t_list *best_node);
void ft_display(t_list *lst_a, t_list *lst_b);
//				SORT.C
void sort_three(t_list **lst_a);
void sort_stack(t_list **lst_a);
void sort_more_than_three(t_list **lst_a, t_list **lst_b);
//				SPLIT.C
size_t	ft_count_word(const char *s, char c);
size_t	ft_word_start(const char *s, char c, size_t i);
void	*ft_free(char **tab);
char	**ft_split(char const *s, char c);
void ft_free_split(char **strs);
//				SWAP.C
void sa(t_list **lst_a);
void sb(t_list **lst_b);
void ss(t_list **lst_a, t_list **lst_b);

#endif