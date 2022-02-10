#include "push_swap.h"

void	smart_rotate(dt_list **stack, int n)
{
	int		size;
	int		steps;
	dt_list	*temp;

	size = ft_cdlstsize(*stack);
	temp = *stack;
	steps = 0;
	while (*(int *)(temp)->content > n)
	{
		steps++;
		temp = temp->next;
	}
	if (steps > (size / 2))
	{
		while (*(int *)(*stack)->content > n)
			rra(stack);
	}
	else
	{	
		while (*(int *)(*stack)->content > n)
			ra(stack);
	}
}

bool	is_sorted(dt_list *stack)
{
	dt_list	*temp;
	int		n;
	int		n_next;

	temp = stack;
	n = *(int *)temp->content;
	while (temp->next != stack)
	{
		n_next = *(int *)temp->content;
		if (n > n_next)
			return (false);
		n = n_next;
		temp = temp->next;
	}
	n_next = *(int *)temp->content;
	if (n > n_next)
		return (false);
	return (true);
}

int	min_stack(dt_list *stack)
{
	dt_list	*temp;
	int		n;

	temp = stack;
	n = *(int *)temp->content;
	while (temp->next != stack)
	{
		if (n > *(int *)temp->content)
			n = *(int *)temp->content;
		temp = temp->next;
	}
	if (n > *(int *)temp->content)
		n = *(int *)temp->content;
	return (n);
}
