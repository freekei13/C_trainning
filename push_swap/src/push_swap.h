#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_pos
{
	int		best_b;
	int		pos_a;
	int		pos_b;
}			t_pos;

void	push_swap(t_list **stack_a, t_list **stack_b);

char	**input_check(int ac, char *av[]);
void	free_lst(t_list **lst);
int		error_check(char **inputs);
int		digit_check(char **inputs);
int		repeat_check(char **inputs);
int		int_minmax_check(char **inputs);
t_list	*parse_inputs(char **args);
int		*parse_index(t_list *args);
void	index_assign(t_list *args);

void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	sa_sb(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list	**stack_a);
void	rotate_b(t_list	**stack_b);
void	ra_rb(t_list **stack_a, t_list **stack_b);
void	re_rotate_a(t_list **stack_a);
void	re_rotate_b(t_list **stack_b);
void	rra_rrb(t_list **stack_a, t_list **stack_b);

int		find_min_index(t_list *stack_a);
int		find_max_index(t_list *stack_a);
int		find_index_pos(t_list *stack_a, int index);
int		find_max(int first, int second);

void	three_args_sort(t_list **stack_a, t_list **stack_b);
void	pre_sort_four(t_list **stack_a, t_list **stack_b, int min);
void	four_args_sort(t_list **stack_a, t_list **stack_b);
void	five_args_sort(t_list **stack_a, t_list **stack_b);

int		*set_lis(t_list *stack_a);
int		set_pos_a_target(t_list *stack_a, int index_b);
int		set_best_pos_b(t_list *stack_a, t_list *stack_b);
int		find_pos_b_index(int pos_b, t_list *stack_b);

int		*cost_diff_scena(int pos_a, int pos_b, int size_a, int size_b);
int		cheapest_cost(int *costs);
int		cheapest_scena(int *costs);

void	scena_action(int pos_a, int pos_b, t_list **a, t_list **b);
void	sort_all(t_list **stack_a, t_list **stack_b);
//For testing only
void	print_stacks(t_list *a, t_list *b);
#endif