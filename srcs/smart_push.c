#include "push_swap.h"

static void	restart_calc(t_calc *calc, t_s *inf_a);
static void	choose_moves(t_s *i_s, t_r *i_r, t_calc *c);
static void	choose_moves_2(t_s *i_s, t_r *i_r, t_calc *c, int min_moves);

void	smart_push_median_print(t_dlist **a, t_dlist **b, t_s *inf_s)
{	
	t_calc	calc;
	t_r		inf_r;

	calc.init_size = inf_s->size;
	restart_calc(&calc, inf_s);
	while (ft_cdlstsize(*b) > 0)
	{
		while (ft_min_int(2, inf_s->rot, inf_s->rrot) < calc.totalmoves
			|| calc.size > calc.counter_r + calc.counter_rr)
		{
			check_sender_stack(*b, inf_s, &calc);
			check_receiver_stack(*a, inf_s, &inf_r);
			choose_moves(inf_s, &inf_r, &calc);
			if (calc.size < calc.counter_r + calc.counter_rr)
				break ;
		}
		execute_moves_print(a, b, &calc, inf_s);
		pa(a, b, inf_s->print);
		inf_s->moves++;
		stack_info(*b, inf_s);
		restart_calc(&calc, inf_s);
	}
}

static void	restart_calc(t_calc *calc, t_s *inf_s)
{
	calc->totalmoves = calc->init_size;
	calc->size = inf_s->size;
	calc->counter_r = 0;
	calc->counter_rr = 0;
	calc->s_move = 0;
	calc->s_num = inf_s->size;
	calc->s_ops = inf_s->size;
	calc->r_move = 0;
	calc->r_num = inf_s->size;
	calc->r_ops = inf_s->size;
	inf_s->rot = 0;
	inf_s->rrot = 0;
}

static void	choose_moves(t_s *i_s, t_r *i_r, t_calc *c)
{
	int	min_moves;

	c->mc1 = ft_max_int(2, i_s->rot, i_r->r_rot);
	c->mc2 = i_s->rot + i_r->r_rrot;
	c->mc3 = i_s->rrot + i_r->rr_rot;
	c->mc4 = ft_max_int(2, i_s->rrot, i_r->rr_rrot);
	min_moves = ft_min_int(4, c->mc1, c->mc2, c->mc3, c->mc4);
	if (min_moves == c->mc1 && min_moves < c->totalmoves)
	{
		c->s_move = 1;
		c->s_ops = i_s->rot;
		c->r_move = 1;
		c->r_ops = i_r->r_rot;
		c->totalmoves = c->mc1;
	}
	if (min_moves == c->mc2 && min_moves < c->totalmoves)
	{
		c->s_move = 1;
		c->s_ops = i_s->rot;
		c->r_move = 2;
		c->r_ops = i_r->r_rrot;
		c->totalmoves = c->mc2;
	}
	choose_moves_2(i_s, i_r, c, min_moves);
}

static void	choose_moves_2(t_s *i_s, t_r *i_r, t_calc *c, int min_moves)
{
	if (min_moves == c->mc3 && min_moves < c->totalmoves)
	{
		c->s_move = 2;
		c->s_ops = i_s->rrot;
		c->r_move = 1;
		c->r_ops = i_r->rr_rot;
		c->totalmoves = c->mc3;
	}
	if (min_moves == c->mc4 && min_moves < c->totalmoves)
	{
		c->s_move = 2;
		c->s_ops = i_s->rrot;
		c->r_move = 2;
		c->r_ops = i_r->rr_rrot;
		c->totalmoves = c->mc4;
	}
}
