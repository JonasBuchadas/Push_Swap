#include "push_swap.h"

static int	set_moves(t_i *inf_a, t_i *inf_b);
static int	set_moves_2(t_i *inf_a, t_i *inf_b, int moves);
static void	execute_move(t_dlist **a, t_dlist **b, int move);

void	smart_push_a(t_dlist **a, t_dlist **b, t_i *inf_a, t_i *inf_b)
{
	int	move;

	check_a(*a, inf_a);
	check_b(*b, inf_b);
	move = set_moves(inf_a, inf_b);
	execute_move(a, b, move);
}

static int	set_moves(t_i *inf_a, t_i *inf_b)
{
	int	min_rot;
	int	min_rrot;
	int	max_rot;
	int	max_rrot;
	int	moves;

	min_rot = max_value(inf_a->min_rot, inf_b->max_rot);
	min_rrot = max_value(inf_a->min_rrot, inf_b->max_rrot);
	max_rot = max_value(inf_a->max_rot, inf_b->min_rot);
	max_rrot = max_value(inf_a->max_rrot, inf_b->min_rrot);
	if (min_rot <= min_rrot && min_rot <= max_rot && min_rot <= max_rrot)
		moves = 1;
	if (min_rrot <= min_rot && min_rrot <= max_rot && min_rrot <= max_rrot)
		moves = 2;
	if (max_rot <= min_rot && max_rot <= min_rrot && max_rot <= max_rrot)
		moves = 3;
	if (max_rrot <= min_rot && max_rrot <= min_rrot && max_rrot <= max_rot)
		moves = 4;
	return (set_moves_2(inf_a, inf_b, moves));
}

static int	set_moves_2(t_i *inf_a, t_i *inf_b, int moves)
{
	if ((moves == 1 && inf_a->min_rot != 0 && inf_b->max_rot != 0)
		|| (moves == 3 && inf_a->max_rot != 0 && inf_b->min_rot != 0))
		return (5);
	if ((moves == 2 && inf_a->min_rrot != 0 && inf_b->max_rrot != 0)
		|| (moves == 4 && inf_a->max_rrot != 0 && inf_b->min_rrot != 0))
		return (6);
	if ((moves == 1 && inf_a->min_rot == 0 && inf_b->max_rot == 0)
		|| (moves == 2 && inf_a->min_rrot == 0 && inf_b->max_rrot == 0)
		|| (moves == 3 && inf_a->max_rot == 0 && inf_b->min_rot == 0)
		|| (moves == 4 && inf_a->max_rrot == 0 && inf_b->min_rrot == 0))
		return (0);
	if ((moves == 1 && inf_a->min_rot != 0 && inf_b->max_rot == 0)
		|| (moves == 3 && inf_a->max_rot != 0 && inf_b->min_rot == 0))
		return (1);
	if ((moves == 1 && inf_a->min_rot == 0 && inf_b->max_rot != 0)
		|| (moves == 3 && inf_a->max_rot == 0 && inf_b->min_rot != 0))
		return (2);
	if ((moves == 2 && inf_a->min_rrot != 0 && inf_b->max_rrot == 0)
		|| (moves == 4 && inf_a->max_rrot != 0 && inf_b->min_rrot == 0))
		return (3);
	if ((moves == 2 && inf_a->min_rrot == 0 && inf_b->max_rrot != 0)
		|| (moves == 4 && inf_a->max_rrot == 0 && inf_b->min_rrot != 0))
		return (4);
	return (-1);
}

static void	execute_move(t_dlist **a, t_dlist **b, int move)
{
	if (move == 0)
		pa(a, b);
	if (move == 1)
		ra(a);
	if (move == 2)
		rb(b);
	if (move == 3)
		rra(a);
	if (move == 4)
		rrb(b);
	if (move == 5)
		rr(a, b);
	if (move == 6)
		rrr(a, b);
}
