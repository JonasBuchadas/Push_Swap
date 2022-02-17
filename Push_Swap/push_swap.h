#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"
# include <stdio.h>

typedef struct stack_info
{
	int	size;
	int	min;
	int	min_rot;
	int	min_rrot;
	int	max;
	int	max_rot;
	int	max_rrot;
	int	median;
	int	rot;
	int	r_num;
	int	rrot;
	int	rr_num;
}			t_i;

void	del(void *num);
void	print(void *num);
void	error(void);
void	mem_clear(char **strlist, t_dlist **stack, int *input);
void	sa(t_dlist **stack);
void	sb(t_dlist **stack);
void	ss(t_dlist **stack_a, t_dlist **stack_b);
void	ra(t_dlist **stack);
void	rb(t_dlist **stack);
void	rr(t_dlist **stack_a, t_dlist **stack_b);
void	rra(t_dlist **stack);
void	rrb(t_dlist **stack);
void	rrr(t_dlist **stack_a, t_dlist **stack_b);
t_dlist	*pa(t_dlist **a, t_dlist **b);
t_dlist	*pb(t_dlist **a, t_dlist **b);
void	sort_size2(t_dlist **stack);
void	sort_size3(t_dlist **stack);
void	sort_size4(t_dlist **stack);
void	sort_size5(t_dlist **stack);
void	sort_medium_size(t_dlist **a);
void	smart_rotate(t_dlist **stack, int n);
bool	is_sorted(t_dlist *stack);
bool	is_sorted_rev(t_dlist *stack);
int		min_stack(t_dlist *stack);
int		max_value(int v1, int v2);
char	**parser(int size, char **strlist);
int		size_strlist(char **strlist);
void	stack_info(t_dlist *stack, t_i *inf);
void	check_a(t_dlist *a, t_i *inf_a);
void	check_b(t_dlist *b, t_i *inf_b);
void	smart_push_median(t_dlist **a, t_dlist **b, t_i *inf_a, t_i *inf_b);
void	smart_push_a(t_dlist **a, t_dlist **b, t_i *inf_a, t_i *inf_b);
#endif
