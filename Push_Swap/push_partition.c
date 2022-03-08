#include "push_swap.h"

static void	check_sender_stack(t_dlist *a, int median, t_s *inf);
static int	choose_moves(t_s *i_s);
static void	execute_moves(t_dlist **a, t_dlist **b, int m);

void	push_partition(t_dlist **s, t_dlist **r, t_s *inf_s)
{	
	int	median;
	int	m;

	median = inf_s->median;
	while (inf_s->min < median && inf_s->size > 5)
	{	
		check_sender_stack(*s, median, inf_s);
		m = choose_moves(inf_s);
		execute_moves(s, r, m);
		stack_info_partition(*s, inf_s);
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
}

static int	choose_moves(t_s *i_s)
{
	if (i_s->rot == 0) 
		return (0);
	else
		return (1);
}

static void	execute_moves(t_dlist **a, t_dlist **b, int m)
{
	if (m == 0)
		pb(a, b);
	else if (m == 1)
		ra(a);
}
