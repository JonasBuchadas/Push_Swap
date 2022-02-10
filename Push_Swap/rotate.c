#include "push_swap.h"

static void	rotate(dt_list **stack)
{
	dt_list	*temp;

	temp = *stack;
	*stack = temp->next;
}

void	ra(dt_list **stack)
{
	rotate(stack);
	write(1, &"ra\n", 3);
}

void	rb(dt_list **stack)
{
	rotate(stack);
	write(1, &"rb\n", 3);
}

void	rr(dt_list **stack_a, dt_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, &"rr\n", 3);
}
