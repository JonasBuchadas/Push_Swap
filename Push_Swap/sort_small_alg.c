#include "push_swap.h"

static int	check_order(t_dlist *stack);

void	sort_size5(t_dlist **a)
{
	t_dlist	*b;
	int		min;

	min = min_stack(*a);
	smart_rotate_a(a, min);
	if (is_sorted(*a))
		return ;
	b = NULL;
	pb(a, &b);
	min = min_stack(*a);
	smart_rotate_a(a, min);
	if (is_sorted(*a))
	{
		pa(a, &b);
		return ;
	}
	pb(a, &b);
	sort_size3(a);
	pa(a, &b);
	pa(a, &b);
}

void	sort_size4(t_dlist **a)
{
	t_dlist	*b;
	int		min;

	min = min_stack(*a);
	smart_rotate_a(a, min);
	if (is_sorted(*a))
		return ;
	b = NULL;
	pb(a, &b);
	sort_size3(a);
	pa(a, &b);
}

void	sort_size3(t_dlist **stack)
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

void	sort_size2(t_dlist **stack)
{
	if (!(is_sorted(*stack)))
		sa(stack);
}

static int	check_order(t_dlist *stack)
{
	int		result;
	t_dlist	*first;
	t_dlist	*second;
	t_dlist	*third;

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
