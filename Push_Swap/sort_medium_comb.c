#include "push_swap.h"

static void	smart_push_a(t_dlist **a, t_dlist **b, t_s *inf_s);
static void	allocate_moves(t_check *t_c, int moves, char *comb);

void	sort_comb(t_dlist **a, t_check *t_c, char *comb)
{
	t_s		inf_s;
	t_dlist	*b;

	b = NULL;
	inf_s.moves = 0;
	inf_s.print = t_c->print;
	stack_info(*a, &inf_s);
	if (comb[0] == 'a')
		push_median_a(a, &b, &inf_s);
	else
		push_median_b(a, &b, &inf_s);
	while (ft_cdlstsize(*a) > 5)
	{
		stack_info(*a, &inf_s);
		if (comb[1] == 'a')
			push_median_a(a, &b, &inf_s);
		else
			push_median_b(a, &b, &inf_s);
	}
	sort_stack_print(a, &b, &inf_s);
	smart_push_a(a, &b, &inf_s);
	smart_rotate_a_print(a, min_stack(*a), &inf_s);
	allocate_moves(t_c, inf_s.moves, comb);
}

static void	smart_push_a(t_dlist **a, t_dlist **b, t_s *inf_s)
{
	while (ft_cdlstsize(*b) > 0)
	{
		stack_info(*b, inf_s);
		smart_push_median_print(a, b, inf_s);
	}
}

static void	allocate_moves(t_check *t_c, int moves, char *comb)
{
	if (comb[0] == 'a' && comb[1] == 'a')
		t_c->aa = moves;
	else if (comb[0] == 'a' && comb[1] == 'b')
		t_c->ab = moves;
	else if (comb[0] == 'b' && comb[1] == 'a')
		t_c->ba = moves;
	else if (comb[0] == 'b' && comb[1] == 'b')
		t_c->bb = moves;
}
