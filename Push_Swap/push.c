#include "push_swap.h"

static void	push(t_dlist **a, t_dlist **b)
{
	t_dlist	*first;
	t_dlist	*temp;
	int		size;

	size = ft_cdlstsize(*a);
	first = *a;
	temp = first->prev;
	temp->next = first->next;
	temp = first->next;
	temp->prev = first->prev;
	*a = first->next;
	first->next = NULL;
	first->prev = NULL;
	ft_cdlstadd_front(b, first);
	if (size == 1)
		*a = NULL;
}

void	pa(t_dlist **a, t_dlist **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_dlist **a, t_dlist **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
