#include "push_swap.h"

static void	reverse_rotate(dt_list **stack)
{
	dt_list	*temp;

	temp = *stack;
	*stack = temp->prev;
}

void	rra(dt_list **stack)
{
	reverse_rotate(stack);
	write(1, &"rra\n", 4);
}

void	rrb(dt_list **stack)
{
	reverse_rotate(stack);
	write(1, &"rrb\n", 4);
}

void	rrr(dt_list **stack_a, dt_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, &"rrr\n", 4);
}
