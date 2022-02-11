#include "push_swap.h"

static void	swap_largelst(dt_list **stack);

static bool	swap(dt_list **stack)
{
	dt_list	*temp;

	temp = *stack;
	if (ft_cdlstsize(temp) == 2)
	{
		*stack = temp->next;
		return (true);
	}
	if (ft_cdlstsize(temp) > 2)
	{
		swap_largelst(stack);
		return (true);
	}
	return (false);
}

static void	swap_largelst(dt_list **stack)
{
	dt_list	*swap1;
	dt_list	*swap2;
	dt_list	*next;
	dt_list	*prev;

	swap1 = *stack;
	swap2 = swap1->next;
	prev = swap1->prev;
	next = swap2->next;
	swap1->next = next;
	swap1->prev = swap2;
	swap2->next = swap1;
	swap2->prev = prev;
	prev->next = swap2;
	next->prev = swap1;
	*stack = swap2;
}

void	sa(dt_list **stack)
{
	if (swap(stack))
		write(1, &"sa\n", 3);
}

void	sb(dt_list **stack)
{
	if (swap(stack))
		write(1, &"sb\n", 3);
}

void	ss(dt_list **stack_a, dt_list **stack_b)
{
	if (swap(stack_a) || swap(stack_b))
		write(1, &"ss\n", 3);
}
