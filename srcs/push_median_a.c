#include "push_swap.h"

static void	check_sender_stack_median(t_dlist *s, int median, t_s *inf);
static void	execute_moves_median(t_dlist **a, t_dlist **b, t_s *i_s);

void	push_median_a(t_dlist **s, t_dlist **r, t_s *inf_s)
{	
	int	median;

	median = inf_s->median;
	while (inf_s->max > median)
	{	
		check_sender_stack_median(*s, median, inf_s);
		execute_moves_median(s, r, inf_s);
		stack_info(*s, inf_s);
	}
}

static void	check_sender_stack_median(t_dlist *s, int median, t_s *inf)
{
	int		r;
	t_dlist	*temp;

	if (!s)
		return ;
	temp = s;
	r = 0;
	while (*(int *)temp->content <= median)
	{
		temp = temp->next;
		r++;
	}
	inf->rot = r;
	inf->r_num = *(int *)temp->content;
}

static void	execute_moves_median(t_dlist **a, t_dlist **b, t_s *i_s)
{
	if (i_s->rot == 0)
		pb(a, b, i_s->print);
	else
		ra(a, i_s->print);
	i_s->moves++;
}	
