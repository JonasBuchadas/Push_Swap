#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"
# include <stdio.h>

typedef struct stack_send_info
{
	int	size;
	int	partitions;
	int	part_size;
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
}			t_s;

typedef struct stack_receiver_info
{
	int	max;
	int	r_num;
	int	r_rot;
	int	r_rrot;
	int	rr_num;
	int	rr_rot;
	int	rr_rrot;
}			t_r;

typedef struct best_moves_calc
{
	int		init_size;
	int		counter_r;
	int		counter_rr;
	int		size;
	int		mc1;
	int		mc2;
	int		mc3;
	int		mc4;
	int		s_num;
	int		s_move;
	int		s_ops;
	int		r_num;
	int		r_move;
	int		r_ops;
	int		totalmoves;
}			t_calc;

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
void	pa(t_dlist **a, t_dlist **b);
void	pb(t_dlist **a, t_dlist **b);
void	sort_stack(t_dlist **stack, int size);
void	sort_large_size(t_dlist **a);
void	smart_rotate_a(t_dlist **stack, int n);
void	smart_rotate_b(t_dlist **stack, int n);
bool	is_sorted(t_dlist *stack);
bool	is_sorted_rev(t_dlist *stack);
int		min_stack(t_dlist *stack);
char	**parser(int size, char **strlist);
int		size_strlist(char **strlist);
void	stack_info(t_dlist *stack, t_s *inf);
void	stack_info_partition(t_dlist *stack, t_s *inf);
void	check_a(t_dlist *a, t_s *inf_s);
void	check_b(t_dlist *b, t_s *inf_r);
void	smart_push_median(t_dlist **a, t_dlist **b, t_s *inf_s, t_r *inf_r);
void	push_median(t_dlist **a, t_dlist **b, t_s *inf_s);
void	push_partition(t_dlist **a, t_dlist **b, t_s *inf_s);
void	check_receiver_stack(t_dlist *r, t_s *inf_s, t_r *inf_r);
void	check_sender_stack(t_dlist *s, t_s *inf, t_calc *calc);
void	execute_moves(t_dlist **a, t_dlist **b, t_calc *c);
void	smart_push_a(t_dlist **a, t_dlist **b, t_s *inf_s, t_r *inf_r);
void	smart_push(t_dlist **s, t_dlist **r, t_s *inf_s, t_r *inf_r);
#endif
