#include "push_swap.h"

static void	push(t_dlist **a, t_dlist **b)
{
	t_dlist	*first;
	t_dlist	*temp;
	int		size;

	if (ft_cdlstsize(*a) > 0)
	{
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
}

void	pa(t_dlist **a, t_dlist **b, bool print)
{
	push(b, a);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_dlist **a, t_dlist **b, bool print)
{
	push(a, b);
	if (print)
		write(1, "pb\n", 3);
}
