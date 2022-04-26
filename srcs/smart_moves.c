#include "push_swap.h"

static void	rra_until_n(t_dlist **stack, int n, t_s *i_s);
static void	ra_until_n(t_dlist **stack, int n, t_s *i_s);

void	smart_rotate_a_print(t_dlist **stack, int n, t_s *i_s)
{
	int		size;
	int		steps;
	t_dlist	*temp;

	size = ft_cdlstsize(*stack);
	temp = *stack;
	steps = 0;
	while (*(int *)(temp)->content != n)
	{
		steps++;
		temp = temp->next;
	}
	if (steps > (size / 2))
		rra_until_n(stack, n, i_s);
	else
		ra_until_n(stack, n, i_s);
}

static void	rra_until_n(t_dlist **stack, int n, t_s *i_s)
{
	while (*(int *)(*stack)->content != n)
	{
		rra(stack, i_s->print);
		i_s->moves++;
	}
}

static void	ra_until_n(t_dlist **stack, int n, t_s *i_s)
{
	while (*(int *)(*stack)->content != n)
	{
		ra(stack, i_s->print);
		i_s->moves++;
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
