#include "push_swap.h"

static void	check_stack_a(t_dlist *a, int median, t_i *inf);
static int	choose_moves(t_i *i_a, t_ib *i_b);
static int	choose_moves_2(t_i *i_a, t_ib *i_b);
static void	execute_moves(t_dlist **a, t_dlist **b, int m);

void	smart_push_median(t_dlist **a, t_dlist **b, t_i *inf_a, t_ib *inf_b)
{	
	int	median;
	int	m;

	median = inf_a->median;
	while (inf_a->min < median)
	{	
		check_stack_a(*a, median, inf_a);
		check_stack_b(*b, inf_a, inf_b);
		m = choose_moves(inf_a, inf_b);
		execute_moves(a, b, m);
		stack_info(*a, inf_a);
	}
}

static void	check_stack_a(t_dlist *a, int median, t_i *inf)
{
	int		r;
	t_dlist	*temp;

	if (!a)
		return ;
	temp = a;
	r = 0;
	while (*(int *)temp->content >= median)
	{
		temp = temp->next;
		r++;
	}
	inf->rot = r;
	inf->r_num = *(int *)temp->content;
	temp = a;
	r = 0;
	while (*(int *)temp->content >= median)
	{
		temp = temp->prev;
		r++;
	}
	inf->rrot = r;
	inf->rr_num = *(int *)temp->content;
}

static int	choose_moves(t_i *i_a, t_ib *i_b)
{
	if ((i_a->rot == 0 || i_a->rrot == 0) 
		&& (i_b->r_rot == 0 || i_b->r_rrot == 0
		|| i_b->rr_rot == 0 || i_b->rr_rrot == 0))
		return (0);
	else if ((i_a->rot != 0 || i_a->rrot != 0) 
		&& (i_b->r_rot == 0 || i_b->r_rrot == 0
		|| i_b->rr_rot == 0 || i_b->rr_rrot == 0))
		{
			if (i_a->rot < i_a->rrot)
				return (1);
			else
				return (2);
		}
	return (choose_moves_2(i_a, i_b));
}

static int	choose_moves_2(t_i *i_a, t_ib *i_b)
{
	int	rdiff;
	int	rrdiff;

	rdiff = i_b->r_rot - i_a->rot;
	rrdiff = i_b->rr_rrot - i_a->rrot;
	if (i_a->rot == 0 || i_a->rrot == 0)
	{
		if (i_b->r_rot < min_value(i_b->r_rrot, i_b->rr_rrot))
			return (3);
		else
			return (4);
	}
	else
	{
		if (i_a->rot < i_a->rrot && rdiff < min_value(i_b->r_rrot, i_b->rr_rrot))
			return (5);
		else
			return (1);
		if (i_a->rrot < i_a->rot && rrdiff < min_value(i_b->r_rot, i_b->rr_rot))
			return (6);
		else
			return (2);	
	}
}

static void	execute_moves(t_dlist **a, t_dlist **b, int m)
{
	if (m == 0)
		pb(a, b);
	else if (m == 1)
		ra(a);
	else if (m == 2)
		rra(a);
	else if (m == 3)
		rb(b);
	else if (m == 4)
		rrb(b);
	else if (m == 5)
		rr(a, b);
	else if (m == 6)
		rrr(a, b);
}
