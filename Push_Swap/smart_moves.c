#include "push_swap.h"

void	smart_rotate(t_dlist **stack, int n)
{
	int		size;
	int		steps;
	t_dlist	*temp;

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

bool	is_sorted(t_dlist *stack)
{
	t_dlist	*temp;
	int		n;
	int		n_next;

	if (!stack)
		return (false);
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

bool	is_sorted_rev(t_dlist *stack)
{
	t_dlist	*temp;
	int		n;
	int		n_next;

	if (!stack)
		return (false);
	temp = stack;
	n = *(int *)temp->content;
	while (temp->next != stack)
	{
		n_next = *(int *)temp->content;
		if (n < n_next)
			return (false);
		n = n_next;
		temp = temp->next;
	}
	n_next = *(int *)temp->content;
	if (n < n_next)
		return (false);
	return (true);
}

int	min_stack(t_dlist *stack)
{
	t_dlist	*temp;
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

int	max_value(int v1, int v2)
{
	int	max_value;

	if (v1 >= v2)
		max_value = v1;
	else
		max_value = v2;
	return (max_value);
}

int	min_value(int v1, int v2)
{
	int	min_value;

	if (v1 <= v2)
		min_value = v1;
	else
		min_value = v2;
	return (min_value);
}