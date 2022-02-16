#include "push_swap.h"

static void	check_stack_a(t_dlist *a, int median, t_i *inf);
static void	check_stack_b(t_dlist *b, t_i *inf_b);
static void	execute_moves(t_dlist **a, t_dlist **b, t_i *inf_b, int m);

void	smart_push_median(t_dlist **a, t_dlist **b, t_i *inf_a, t_i *inf_b)
{	
	int	median;
	int	m;

	median = inf_a->median;
	while (inf_a->min < median)
	{	
		check_stack_a(*a, median, inf_a);
		check_stack_b(*b, inf_b);
		if (inf_b->rot > inf_a->rot)
			inf_b->rot = 0;
		if (inf_b->rrot > inf_a->rrot)
			inf_b->rrot = 0;
		if (inf_a->rot == 0 || inf_a->rrot == 0)
			m = 0;
		else if (inf_a->rot <= inf_a->rrot)
			m = 1;
		else
			m = -1;
		execute_moves(a, b, inf_b, m);
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

static void	check_stack_b(t_dlist *b, t_i *inf_b)
{
	int		r;
	t_dlist	*temp;

	if (!b || is_sorted_rev(b))
	{	
		inf_b->rot = 0;
		inf_b->rrot = 0;
		return ;
	}
	temp = b;
	r = 0;
	while (!is_sorted_rev(temp) && temp->next != b)
	{
		temp = temp->next;
		r++;
	}
	inf_b->rot = r;
	temp = b;
	r = 0;
	while (!is_sorted_rev(temp) && temp->prev != b)
	{
		temp = temp->prev;
		r++;
	}
	inf_b->rrot = r;
}

static void	execute_moves(t_dlist **a, t_dlist **b, t_i *inf_b, int m)
{
	if (m == 1)
	{
		if (!b || ft_cdlstsize(*b) < 2 || inf_b->rot == 0)
			ra(a);
		else
			rr(a, b);
	}
	if (m == -1)
	{
		if (!b || ft_cdlstsize(*b) < 2 || inf_b->rrot == 0)
			rra(a);
		else
			rrr(a, b);
	}
	if (m == 0)
		pb(a, b);
}
