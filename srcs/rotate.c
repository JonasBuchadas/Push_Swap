#include "push_swap.h"

static void	rotate(t_dlist **stack)
{
	t_dlist	*temp;

	if (*stack && ft_cdlstsize(*stack) > 1)
	{
		temp = *stack;
		*stack = temp->next;
	}
}

void	ra(t_dlist **stack, bool print)
{
	rotate(stack);
	if (print)
		write(1, &"ra\n", 3);
}

void	rb(t_dlist **stack, bool print)
{
	rotate(stack);
	if (print)
		write(1, &"rb\n", 3);
}

void	rr(t_dlist **stack_a, t_dlist **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		write(1, &"rr\n", 3);
}
