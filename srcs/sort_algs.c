#include "push_swap.h"

static void	sort_size5(t_dlist **a);
static void	sort_size4(t_dlist **a);
static void	sort_size3(t_dlist **stack);

void	sort_stack(t_dlist **stack, int *arr)
{
	int	size;

	size = ft_cdlstsize(*stack);
	if (size == 2)
	{
		if (!(is_sorted(*stack)))
			sa(stack, true);
	}
	else if (size == 3)
		sort_size3(stack);
	else if (size == 4)
		sort_size4(stack);
	else if (size == 5)
		sort_size5(stack);
	else if (size <= 100)
		sort_medium_size(stack, arr);
	else
		sort_large_size(stack);
}

static void	sort_size5(t_dlist **a)
{
	t_dlist	*b;
	int		min;

	min = min_stack(*a);
	smart_rotate_a(a, min);
	if (is_sorted(*a))
		return ;
	b = NULL;
	pb(a, &b, true);
	min = min_stack(*a);
	smart_rotate_a(a, min);
	if (is_sorted(*a))
	{
		pa(a, &b, true);
		return ;
	}
	pb(a, &b, true);
	sort_size3(a);
	pa(a, &b, true);
	pa(a, &b, true);
}

static void	sort_size4(t_dlist **a)
{
	t_dlist	*b;
	int		min;

	min = min_stack(*a);
	smart_rotate_a(a, min);
	if (is_sorted(*a))
		return ;
	b = NULL;
	pb(a, &b, true);
	sort_size3(a);
	pa(a, &b, true);
}

static void	sort_size3(t_dlist **stack)
{
	int	condition;

	condition = check_order(*stack);
	if (condition == 1)
		sa(stack, true);
	else if (condition == 2)
	{
		sa(stack, true);
		ra(stack, true);
	}
	else if (condition == 5)
		ra(stack, true);
	else if (condition == 6)
		rra(stack, true);
	else if (condition == 7)
	{
		sa(stack, true);
		rra(stack, true);
	}
}

int	check_order(t_dlist *stack)
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
