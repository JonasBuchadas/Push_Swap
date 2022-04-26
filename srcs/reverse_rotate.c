#include "push_swap.h"

static void	reverse_rotate(t_dlist **stack)
{
	t_dlist	*temp;

	temp = *stack;
	*stack = temp->prev;
}

void	rra(t_dlist **stack, bool print)
{
	reverse_rotate(stack);
	if (print)
		write(1, &"rra\n", 4);
}

void	rrb(t_dlist **stack, bool print)
{
	reverse_rotate(stack);
	if (print)
		write(1, &"rrb\n", 4);
}

void	rrr(t_dlist **stack_a, t_dlist **stack_b, bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		write(1, &"rrr\n", 4);
}
