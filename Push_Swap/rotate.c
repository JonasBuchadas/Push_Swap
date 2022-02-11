#include "push_swap.h"

static void	rotate(t_dlist **stack)
{
	t_dlist	*temp;

	temp = *stack;
	*stack = temp->next;
}

void	ra(t_dlist **stack)
{
	rotate(stack);
	write(1, &"ra\n", 3);
}

void	rb(t_dlist **stack)
{
	rotate(stack);
	write(1, &"rb\n", 3);
}

void	rr(t_dlist **stack_a, t_dlist **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, &"rr\n", 3);
}
