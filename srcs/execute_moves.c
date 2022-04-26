#include "push_swap.h"

static void	double_moves(t_dlist **a, t_dlist **b, t_calc *c, t_s *i_s);
static void	moves_b(t_dlist **b, t_calc *c, t_s *i_s);
static void	moves_a(t_dlist **a, t_calc *c, t_s *i_s);

void	execute_moves_print(t_dlist **a, t_dlist **b, t_calc *c, t_s *i_s)
{
	while (c->s_ops > 0 || c->r_ops > 0)
	{
		if (c->s_ops > 0 && c->r_ops > 0)
			double_moves(a, b, c, i_s);
		if (c->s_ops > 0)
			moves_b(b, c, i_s);
		if (c->r_ops > 0)
			moves_a(a, c, i_s);
	}
}

static void	double_moves(t_dlist **a, t_dlist **b, t_calc *c, t_s *i_s)
{
	if (c->s_move == 1 && c->r_move == 1)
	{
		rr(a, b, i_s->print);
		c->s_ops--;
		c->r_ops--;
		i_s->moves++;
	}
	if (c->s_move == 2 && c->r_move == 2)
	{
		rrr(a, b, i_s->print);
		c->s_ops--;
		c->r_ops--;
		i_s->moves++;
	}
}

static void	moves_b(t_dlist **b, t_calc *c, t_s *i_s)
{
	if (c->s_move == 1)
		rb(b, i_s->print);
	if (c->s_move == 2)
		rrb(b, i_s->print);
	c->s_ops--;
	i_s->moves++;
}

static void	moves_a(t_dlist **a, t_calc *c, t_s *i_s)
{
	if (c->r_move == 1)
		ra(a, i_s->print);
	if (c->r_move == 2)
		rra(a, i_s->print);
	c->r_ops--;
	i_s->moves++;
}
