#include "push_swap.h"

static void	swap_largelst(t_dlist **stack);

static bool	swap(t_dlist **stack)
{
	t_dlist	*temp;

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

static void	swap_largelst(t_dlist **stack)
{
	t_dlist	*swap1;
	t_dlist	*swap2;
	t_dlist	*next;
	t_dlist	*prev;

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

void	sa(t_dlist **stack, bool print)
{
	if (swap(stack) && print)
		write(1, &"sa\n", 3);
}

void	sb(t_dlist **stack, bool print)
{
	if (swap(stack) && print)
		write(1, &"sb\n", 3);
}

void	ss(t_dlist **stack_a, t_dlist **stack_b, bool print)
{
	if ((swap(stack_a) || swap(stack_b)) && print)
		write(1, &"ss\n", 3);
}
