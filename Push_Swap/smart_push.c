#include "push_swap.h"

static void	check_sender_stack(t_dlist *s, int median, t_s *inf);
static int	choose_moves(t_s *i_s, t_r *i_r);
static int	choose_moves_2(t_s *i_s, t_r *i_r);
static void	execute_moves(t_dlist **s, t_dlist **r, int m);

void	smart_push(t_dlist **s, t_dlist **r, t_s *inf_s, t_r *inf_r)
{	
	int	median;
	int	m;

	median = inf_s->median;
	while (inf_s->min < median)
	{	
		check_sender_stack(*s, median, inf_s);
		check_receiver_stack(*r, inf_s, inf_r);
		m = choose_moves(inf_s, inf_r);
		execute_moves(s, r, m);
		stack_info(*s, inf_s);
	}
}

static void	check_sender_stack(t_dlist *s, int median, t_s *inf)
{
	int		r;
	t_dlist	*temp;

	if (!s)
		return ;
	temp = s;
	r = 0;
	while (*(int *)temp->content >= median)
	{
		temp = temp->next;
		r++;
	}
	inf->rot = r;
	inf->r_num = *(int *)temp->content;
	temp = s;
	r = 0;
	while (*(int *)temp->content >= median)
	{
		temp = temp->prev;
		r++;
	}
	inf->rrot = r;
	inf->rr_num = *(int *)temp->content;
}

static int	choose_moves(t_s *i_s, t_r *i_r)
{
	if ((i_s->rot == 0 || i_s->rrot == 0) 
		&& (i_r->r_rot == 0 || i_r->r_rrot == 0
		|| i_r->rr_rot == 0 || i_r->rr_rrot == 0))
		return (0);
	else if ((i_s->rot != 0 || i_s->rrot != 0) 
		&& (i_r->r_rot == 0 || i_r->r_rrot == 0
		|| i_r->rr_rot == 0 || i_r->rr_rrot == 0))
		{
			if (i_s->rot < i_s->rrot)
				return (1);
			else
				return (2);
		}
	return (choose_moves_2(i_s, i_r));
}

static int	choose_moves_2(t_s *i_s, t_r *i_r)
{
	int	rdiff;
	int	rrdiff;

	rdiff = i_r->r_rot - i_s->rot;
	rrdiff = i_r->rr_rrot - i_s->rrot;
	if (i_s->rot == 0 || i_s->rrot == 0)
	{
		if (i_r->r_rot < min_value(i_r->r_rrot, i_r->rr_rrot))
			return (3);
		else
			return (4);
	}
	else
	{
		if (i_s->rot < i_s->rrot && rdiff < min_value(i_r->r_rrot, i_r->rr_rrot))
			return (5);
		else
			return (1);
		if (i_s->rrot < i_s->rot && rrdiff < min_value(i_r->r_rot, i_r->rr_rot))
			return (6);
		else
			return (2);	
	}
}

static void	execute_moves(t_dlist **s, t_dlist **r, int m)
{
	if (m == 0)
		pa(s, r);
	else if (m == 1)
		rb(s);
	else if (m == 2)
		rrb(s);
	else if (m == 3)
		ra(r);
	else if (m == 4)
		rra(r);
	else if (m == 5)
		rr(r, s);
	else if (m == 6)
		rrr(r, s);
}
