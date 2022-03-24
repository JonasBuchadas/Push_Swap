#include "push_swap.h"

static void	select_comb(t_dlist **a, t_check *inf_c);

void	sort_medium_size(t_dlist **a, int *arr)
{
	t_check		inf_c;
	t_dlist		*c_aa;
	t_dlist		*c_ab;
	t_dlist		*c_ba;
	t_dlist		*c_bb;

	c_aa = create_stack(arr, ft_cdlstsize(*a));
	c_ab = create_stack(arr, ft_cdlstsize(*a));
	c_ba = create_stack(arr, ft_cdlstsize(*a));
	c_bb = create_stack(arr, ft_cdlstsize(*a));
	inf_c.print = false;
	sort_comb(&c_aa, &inf_c, "aa");
	sort_comb(&c_ab, &inf_c, "ab");
	sort_comb(&c_ba, &inf_c, "ba");
	sort_comb(&c_bb, &inf_c, "bb");
	inf_c.print = true;
	select_comb(a, &inf_c);
	ft_cdlstclear(&c_aa, &del);
	ft_cdlstclear(&c_ab, &del);
	ft_cdlstclear(&c_ba, &del);
	ft_cdlstclear(&c_bb, &del);
}

static void	select_comb(t_dlist **a, t_check *inf_c)
{
	int	min_moves;

	min_moves = ft_min_int(4, inf_c->aa, inf_c->ab, inf_c->ba, inf_c->bb);
	if (min_moves == inf_c->aa)
		sort_comb(a, inf_c, "aa");
	else if (min_moves == inf_c->ab)
		sort_comb(a, inf_c, "ab");
	else if (min_moves == inf_c->ba)
		sort_comb(a, inf_c, "ba");
	else if (min_moves == inf_c->bb)
		sort_comb(a, inf_c, "bb");
}
