#include "push_swap.h"

static void	sort_size5(t_dlist **a, t_dlist **b, t_s *t_c);
static void	sort_size4(t_dlist **a, t_dlist **b, t_s *t_c);
static void	sort_size3(t_dlist **a, t_s *t_c);
static void	sort_size3_2(t_dlist **a, t_s *t_c, int condition);

void	sort_stack_print(t_dlist **a, t_dlist **b, t_s *t_c)
{
	int		size;

	size = ft_cdlstsize(*a);
	if (size == 2)
	{
		if (!(is_sorted(*a)))
		{
			sa(a, t_c->print);
			t_c->moves++;
		}
	}
	else if (size == 3)
		sort_size3(a, t_c);
	else if (size == 4)
		sort_size4(a, b, t_c);
	else if (size == 5)
		sort_size5(a, b,t_c);
}

static void	sort_size5(t_dlist **a, t_dlist **b, t_s *t_c)
{
	int		min;

	min = min_stack(*a);
	smart_rotate_a_print(a, min, t_c);
	if (is_sorted(*a))
		return ;
	pb(a, b, t_c->print);
	t_c->moves++;
	min = min_stack(*a);
	smart_rotate_a_print(a, min, t_c);
	if (is_sorted(*a))
	{
		pa(a, b, t_c->print);
		t_c->moves++;
		return ;
	}
	pb(a, b, t_c->print);
	t_c->moves++;
	sort_size3(a, t_c);
	pa(a, b, t_c->print);
	pa(a, b, t_c->print);
	t_c->moves = t_c->moves + 2;
}

static void	sort_size4(t_dlist **a, t_dlist **b, t_s *t_c)
{
	int		min;

	min = min_stack(*a);
	smart_rotate_a_print(a, min, t_c);
	if (is_sorted(*a))
		return ;
	pb(a, b, t_c->print);
	t_c->moves++;
	sort_size3(a, t_c);
	pa(a, b, t_c->print);
}

static void	sort_size3(t_dlist **a, t_s *t_c)
{
	int	condition;

	condition = check_order(*a);
	if (condition == 1)
	{
		sa(a, t_c->print);
		t_c->moves++;
	}
	else if (condition == 2)
	{
		sa(a, t_c->print);
		ra(a, t_c->print);
		t_c->moves = t_c->moves + 2;
	}
	else
		sort_size3_2(a, t_c, condition);
}

static void	sort_size3_2(t_dlist **a, t_s *t_c, int condition)
{
	if (condition == 5)
	{
		ra(a, t_c->print);
		t_c->moves++;
	}
	else if (condition == 6)
	{
		rra(a, t_c->print);
		t_c->moves++;
	}
	else if (condition == 7)
	{
		sa(a, t_c->print);
		rra(a, t_c->print);
		t_c->moves = t_c->moves + 2;
	}
}
