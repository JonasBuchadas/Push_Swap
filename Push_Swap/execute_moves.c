#include "push_swap.h"

static void	double_moves(t_dlist **a, t_dlist **b, t_calc *c);
static void	moves_b(t_dlist **b, t_calc *c);
static void	moves_a(t_dlist **a, t_calc *c);

void	execute_moves(t_dlist **a, t_dlist **b, t_calc *c)
{
	while (c->s_ops > 0 || c->r_ops > 0)
	{
		if (c->s_ops > 0 && c->r_ops > 0)
			double_moves(a, b, c);
		if (c->s_ops > 0)
			moves_b(b, c);
		if (c->r_ops > 0)
			moves_a(a, c);
	}
}

static void	double_moves(t_dlist **a, t_dlist **b, t_calc *c)
{
	if (c->s_move == 1 && c->r_move == 1)
	{
		rr(a, b, true);
		c->s_ops--;
		c->r_ops--;
	}
	if (c->s_move == 2 && c->r_move == 2)
	{
		rrr(a, b, true);
		c->s_ops--;
		c->r_ops--;
	}
}

static void	moves_b(t_dlist **b, t_calc *c)
{
	if (c->s_move == 1)
		rb(b, true);
	if (c->s_move == 2)
		rrb(b, true);
	c->s_ops--;
}

static void	moves_a(t_dlist **a, t_calc *c)
{
	if (c->r_move == 1)
		ra(a, true);
	if (c->r_move == 2)
		rra(a, true);
	c->r_ops--;
}
