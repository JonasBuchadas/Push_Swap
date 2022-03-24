#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"
# include <stdio.h>

typedef struct stack_send_info
{
	bool	print;
	int		moves;
	int		size;
	int		partitions;
	int		part_size;
	int		min;
	int		min_rot;
	int		min_rrot;
	int		max;
	int		max_rot;
	int		max_rrot;
	int		median;
	int		rot;
	int		r_num;
	int		rrot;
	int		rr_num;
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

typedef struct check_best_alg
{
	bool	print;
	int		moves;
	int		aa;
	int		ab;
	int		ba;
	int		bb;
	char	*best_move;
}			t_check;

void	del(void *num);
void	error(void);
t_dlist	*create_stack(int *input, int size);
void	mem_clear(char **strlist, t_dlist **stack, int *input);
void	sa(t_dlist **stack, bool print);
void	sb(t_dlist **stack, bool print);
void	ss(t_dlist **stack_a, t_dlist **stack_b, bool print);
void	ra(t_dlist **stack, bool print);
void	rb(t_dlist **stack, bool print);
void	rr(t_dlist **stack_a, t_dlist **stack_b, bool print);
void	rra(t_dlist **stack, bool print);
void	rrb(t_dlist **stack, bool print);
void	rrr(t_dlist **stack_a, t_dlist **stack_b, bool print);
void	pa(t_dlist **a, t_dlist **b, bool print);
void	pb(t_dlist **a, t_dlist **b, bool print);
void	sort_stack(t_dlist **stack, int *arr);
void	sort_stack_print(t_dlist **stack, t_s *t_c);
int		check_order(t_dlist *stack);
void	sort_large_size(t_dlist **a);
void	sort_medium_size(t_dlist **a, int *arr);
void	sort_comb(t_dlist **a, t_check *t_c, char *comb);
void	smart_rotate_a(t_dlist **stack, int n);
void	smart_rotate_a_print(t_dlist **stack, int n, t_s *i_s);
bool	is_sorted(t_dlist *stack);
int		min_stack(t_dlist *stack);
char	**parser(int size, char **strlist);
int		size_strlist(char **strlist);
void	stack_info(t_dlist *stack, t_s *inf);
void	smart_push_median_print(t_dlist **a, t_dlist **b, t_s *inf_s);
void	push_median_a(t_dlist **a, t_dlist **b, t_s *inf_s);
void	push_median_b(t_dlist **a, t_dlist **b, t_s *inf_s);
void	check_receiver_stack(t_dlist *r, t_s *inf_s, t_r *inf_r);
void	check_sender_stack(t_dlist *s, t_s *inf, t_calc *calc);
void	execute_moves_print(t_dlist **a, t_dlist **b, t_calc *c, t_s *i_s);
#endif
