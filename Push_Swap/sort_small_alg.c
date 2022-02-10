#include "push_swap.h"

static int	check_order(dt_list *stack);

void	sort_size5(dt_list **a)
{
	dt_list	*b;
	int		min;

	min = min_stack(*a);
	smart_rotate(a, min);
	if (is_sorted(*a))
		return ;
	b = NULL;
	b = pb(a, &b);
	min = min_stack(*a);
	smart_rotate(a, min);
	if (is_sorted(*a))
	{
		(*a) = pa(a, &b);
		return ;
	}
	b = pb(a, &b);
	sort_size3(a);
	(*a) = pa(a, &b);
	(*a) = pa(a, &b);
}

void	sort_size4(dt_list **a)
{
	dt_list	*b;
	int		min;

	min = min_stack(*a);
	smart_rotate(a, min);
	if (is_sorted(*a))
		return ;
	b = NULL;
	b = pb(a, &b);
	sort_size3(a);
	(*a) = pa(a, &b);
}

void	sort_size3(dt_list **stack)
{
	int	condition;

	condition = check_order(*stack);
	if (condition == 1)
		sa(stack);
	else if (condition == 2)
	{
		sa(stack);
		ra(stack);
	}
	else if (condition == 5)
		ra(stack);
	else if (condition == 6)
		rra(stack);
	else if (condition == 7)
	{
		sa(stack);
		rra(stack);
	}
}

static int	check_order(dt_list *stack)
{
	int		result;
	dt_list	*first;
	dt_list	*second;
	dt_list	*third;

	first = stack;
	second = first->next;
	third = second->next;
	result = 0;
	if (*((int *)first->content) > (*((int *)second->content)))
		result += 1;
	if (*((int *)second->content) > (*((int *)third->content)))
		result += 2;
	if (*((int *)first->content) > (*((int *)third->content)))
		result += 4;
	return (result);
}
