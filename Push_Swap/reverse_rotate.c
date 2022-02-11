#include "push_swap.h"

static void	reverse_rotate(t_dlist **stack)
{
	t_dlist	*temp;

	temp = *stack;
	*stack = temp->prev;
}

void	rra(t_dlist **stack)
{
	reverse_rotate(stack);
	write(1, &"rra\n", 4);
}

void	rrb(t_dlist **stack)
{
	reverse_rotate(stack);
	write(1, &"rrb\n", 4);
}

void	rrr(t_dlist **stack_a, t_dlist **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, &"rrr\n", 4);
}
