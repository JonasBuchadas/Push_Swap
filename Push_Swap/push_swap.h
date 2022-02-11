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
	int	max;
	int	median;
	int	rot;
	int	rrot;
}			t_i;

void	del(void *num);
void	print(void *num);
void	error(void);
void	mem_clear(char **strlist, dt_list **stack, int *input);
void	sa(dt_list **stack);
void	sb(dt_list **stack);
void	ss(dt_list **stack_a, dt_list **stack_b);
void	ra(dt_list **stack);
void	rb(dt_list **stack);
void	rr(dt_list **stack_a, dt_list **stack_b);
void	rra(dt_list **stack);
void	rrb(dt_list **stack);
void	rrr(dt_list **stack_a, dt_list **stack_b);
dt_list	*pa(dt_list **a, dt_list **b);
dt_list	*pb(dt_list **a, dt_list **b);
void	sort_size3(dt_list **stack);
void	sort_size4(dt_list **stack);
void	sort_size5(dt_list **stack);
void	sort_medium_size(dt_list **a);
void	smart_rotate(dt_list **stack, int n);
bool	is_sorted(dt_list *stack);
int		min_stack(dt_list *stack);
char	**parser(int size, char **strlist);
int		size_strlist(char **strlist);
void	stack_info(dt_list *stack, t_i *inf);
void	smart_2stack_rotate(dt_list **a, dt_list **b, t_i *inf_a, t_i *inf_b);
#endif
