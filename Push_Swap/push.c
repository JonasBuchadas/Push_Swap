#include "push_swap.h"

static void	push(dt_list **a, dt_list **b)
{
	dt_list	*first;
	dt_list	*temp;

	first = *a;
	temp = first->prev;
	temp->next = first->next;
	temp = first->next;
	temp->prev = first->prev;
	*a = first->next;
	first->next = NULL;
	first->prev = NULL;
	ft_cdlstadd_front(b, first);
}

dt_list	*pa(dt_list **a, dt_list **b)
{
	push(b, a);
	write(1, "pa\n", 3);
	return (*a);
}

dt_list	*pb(dt_list **a, dt_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
	return (*b);
}
