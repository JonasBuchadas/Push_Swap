#include "push_swap.h"

static void	sort_size5(t_dlist **a, t_s *t_c);
static void	sort_size4(t_dlist **a, t_s *t_c);
static void	sort_size3(t_dlist **stack, t_s *t_c);
static void	sort_size3_2(t_dlist **stack, t_s *t_c, int condition);

void	sort_stack_print(t_dlist **stack, t_s *t_c)
{
	int		size;

	size = ft_cdlstsize(*stack);
	if (size == 2)
	{
		if (!(is_sorted(*stack)))
		{
			sa(stack, t_c->print);
			t_c->moves++;
		}
	}
	else if (size == 3)
		sort_size3(stack, t_c);
	else if (size == 4)
		sort_size4(stack, t_c);
	else if (size == 5)
		sort_size5(stack, t_c);
}

static void	sort_size5(t_dlist **a, t_s *t_c)
{
	t_dlist	*b;
	int		min;

	min = min_stack(*a);
	smart_rotate_a_print(a, min, t_c);
	if (is_sorted(*a))
		return ;
	b = NULL;
	pb(a, &b, t_c->print);
	t_c->moves++;
	min = min_stack(*a);
	smart_rotate_a_print(a, min, t_c);
	if (is_sorted(*a))
	{
		pa(a, &b, t_c->print);
		t_c->moves++;
		return ;
	}
	pb(a, &b, t_c->print);
	t_c->moves++;
	sort_size3(a, t_c);
	pa(a, &b, t_c->print);
	pa(a, &b, t_c->print);
	t_c->moves = t_c->moves + 2;
}

static void	sort_size4(t_dlist **a, t_s *t_c)
{
	t_dlist	*b;
	int		min;

	min = min_stack(*a);
	smart_rotate_a_print(a, min, t_c);
	if (is_sorted(*a))
		return ;
	b = NULL;
	pb(a, &b, t_c->print);
	t_c->moves++;
	sort_size3(a, t_c);
	pa(a, &b, t_c->print);
}

static void	sort_size3(t_dlist **stack, t_s *t_c)
{
	int	condition;

	condition = check_order(*stack);
	if (condition == 1)
	{
		sa(stack, t_c->print);
		t_c->moves++;
	}
	else if (condition == 2)
	{
		sa(stack, t_c->print);
		ra(stack, t_c->print);
		t_c->moves = t_c->moves + 2;
	}
	else
		sort_size3_2(stack, t_c, condition);
}

static void	sort_size3_2(t_dlist **stack, t_s *t_c, int condition)
{
	if (condition == 5)
	{
		ra(stack, t_c->print);
		t_c->moves++;
	}
	else if (condition == 6)
	{
		rra(stack, t_c->print);
		t_c->moves++;
	}
	else if (condition == 7)
	{
		sa(stack, t_c->print);
		rra(stack, t_c->print);
		t_c->moves = t_c->moves + 2;
	}
}
