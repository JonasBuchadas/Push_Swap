#include "push_swap.h"

void	check_stack_a(t_dlist *a, t_i *inf);
void	check_stack_b(t_dlist *b, t_i *inf_a, t_i *inf_b);
int		set_moves(t_dlist **a, t_dlist **b, t_i *inf_a, t_i *inf_b);
void	execute_moves(t_dlist **a, t_dlist **b, int m);

void	smart_2stack_rotate(t_dlist **a, t_dlist **b, t_i *inf_a, t_i *inf_b)
{	
	int	m;

	while (ft_cdlstsize(*b) != 2)
	{
		m = set_moves(a, b, inf_a, inf_b);
		execute_moves(a, b, m);
	}
}

int	set_moves(t_dlist **a, t_dlist **b, t_i *inf_a, t_i *inf_b)
{
	check_stack_a(*a, inf_a);
	check_stack_b(*b, inf_a, inf_b);
	printf("Median: %i\n", inf_a->median);
	printf("MinRot: %i\n", inf_a->rot);
	printf("MinRRot: %i\n", inf_a->rrot);
	printf("Size_B: %i\n", ft_cdlstsize(*b));
	if (ft_cdlstsize(*b) < 2)
	{
		if (inf_a->rot == 0 || inf_a->rrot == 0)
			return (1);
		if (inf_a->rot <= inf_a->rrot)
			return (2);
		else
			return (3);
	}
	return (0);
}

void	check_stack_a(t_dlist *a, t_i *inf)
{
	int		r;
	t_dlist	*temp;

	if (!a)
		return ;
	temp = a;
	r = 0;
	while (*(int *)temp->content >= inf->median)
	{
		temp = temp->next;
		r++;
	}
	inf->rot = r;
	inf->r_num = *(int *)temp->content;
	temp = a;
	r = 0;
	while (*(int *)temp->content >= inf->median)
	{
		temp = temp->prev;
		r++;
	}
	inf->rrot = r;
	inf->rr_num = *(int *)temp->content;
}

void	check_stack_b(t_dlist *b, t_i *inf_a, t_i *inf_b)
{
	int		r;
	t_dlist	*temp;

	if (!b)
		return ;
	temp = b;
	while (*(int *)temp->content >= inf_a->r_num)
	{
		temp = temp->next;
		if (temp == b) 
		{
			r = 0;
			break;
		}
		r++;
	}
	inf_b->rot = r;
	temp = b;
	r = 0;
	while (*(int *)temp->content >= inf_a->rr_num)
	{
		temp = temp->prev;
		if (temp == b)
		{
			r = 0;
			break;
		}
		r++;
	}
	inf_b->rrot = r;
}

void	execute_moves(t_dlist **a, t_dlist **b, int m)
{
	if (m == 1)
		pb(a, b);
	if (m == 2)
		ra(a);
	if (m == 3)
		rra(a);
}
