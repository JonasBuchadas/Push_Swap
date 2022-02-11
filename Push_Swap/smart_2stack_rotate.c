#include "push_swap.h"

void	check_stack_a(t_dlist *a, t_i *inf);
void	check_stack_b(t_dlist *b, t_i *inf);
void	set_moves(t_dlist *a, t_dlist *b, t_i *inf_a, t_i *inf_b);

void	smart_2stack_rotate(t_dlist **a, t_dlist **b, t_i *inf_a, t_i *inf_b)
{	
	set_moves(*a, *b, inf_a, inf_b);
}

void	set_moves(t_dlist *a, t_dlist *b, t_i *inf_a, t_i *inf_b)
{
	check_stack_a(a, inf_a);
	check_stack_b(b, inf_b);
}

void	check_stack_a(t_dlist *a, t_i *inf)
{
	int		r;
	int		rr;
	t_dlist	*temp;

	if (!a)
		return ;
	temp = a;
	while (*(int *)temp->content >= inf->median)
	{
		temp = temp->next;
		r++;
	}
	temp = a;
	while (*(int *)temp->content >= inf->median)
	{
		temp = temp->prev;
		rr++;
	}
	inf->rot = r;
	inf->rrot = rr;
}

void	check_stack_b(t_dlist *b, t_i *inf)
{
	int		r;
	int		rr;
	t_dlist	*temp;

	if (!b)
		return ;
	temp = b;
	while (*(int *)temp->content >= inf->median)
	{
		temp = temp->next;
		r++;
	}
	temp = b;
	while (*(int *)temp->content >= inf->median)
	{
		temp = temp->prev;
		rr++;
	}
	inf->rot = r;
	inf->rrot = rr;
}
