#include "push_swap.h"

static void	calc_rot_moves(t_dlist *s, t_s *inf, t_calc *calc);
static void	calc_rrot_moves(t_dlist *s, t_s *inf, t_calc *calc);

void	check_sender_stack(t_dlist *s, t_s *inf, t_calc *calc)
{
	if (!s)
		return ;
	calc_rot_moves(s, inf, calc);
	calc_rrot_moves(s, inf, calc);
}

static void	calc_rot_moves(t_dlist *s, t_s *inf, t_calc *calc)
{
	int		r;
	int		i;
	t_dlist	*temp;

	temp = s;
	i = 0;
	r = 0;
	while (i <= calc->counter_r)
	{
		temp = temp->next;
		r++;
		i++;
	}
	inf->rot = r;
	inf->r_num = *(int *)temp->content;
	calc->counter_r++;
}

static void	calc_rrot_moves(t_dlist *s, t_s *inf, t_calc *calc)
{
	int		r;
	int		i;
	t_dlist	*temp;

	temp = s;
	i = 0;
	r = 0;
	while (i <= calc->counter_rr)
	{
		temp = temp->prev;
		r++;
		i++;
	}
	inf->rrot = r;
	inf->rr_num = *(int *)temp->content;
	calc->counter_rr++;
}
