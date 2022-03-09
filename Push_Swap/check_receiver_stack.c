#include "push_swap.h"

static void	analyze_r(t_dlist *r, t_s *inf_s, t_r *inf_r);
static void	r_insert_values(int *sorted, int max, t_s *inf_s, t_r *inf_r);
static void	min_rmoves_r(t_dlist *b, t_r *inf_r);
static void	min_rrmoves_r(t_dlist *b, t_r *inf_r);

void	check_receiver_stack(t_dlist *r, t_s *inf_s, t_r *inf_r)
{
	if (!r)
	{	
		inf_r->r_rot = 0;
		inf_r->r_rrot = 0;
		inf_r->rr_rot = 0;
		inf_r->rr_rrot = 0;
		return ;
	}
	analyze_r(r, inf_s, inf_r);
	min_rmoves_r(r, inf_r);
	min_rrmoves_r(r, inf_r);
}

static void	analyze_r(t_dlist *r, t_s *inf_s, t_r *inf_r)
{
	int		*sorted;
	t_dlist	*temp;
	int		i;
	int		size;

	if (!r)
		return ;
	size = ft_cdlstsize(r);
	sorted = (int *)malloc(sizeof(int) * size);
	i = -1;
	temp = r;
	while (temp->next != r)
	{
		sorted[++i] = *(int *)temp->content;
		temp = temp->next;
	}
	sorted[++i] = *(int *)temp->content;
	ft_sort_int_tab(sorted, size);
	r_insert_values(sorted, i, inf_s, inf_r);
	free(sorted);
}

static void	r_insert_values(int *sorted, int max, t_s *inf_s, t_r *inf_r)
{
	int	i;

	i = 0;
	if (inf_s->r_num < sorted[0] || inf_s->r_num > sorted[max])
		inf_r->r_num = sorted[0];
	else
	{
		while (inf_s->r_num > sorted[i])
			i++;
		inf_r->r_num = sorted[i];
	}
	i = 0;
	if (inf_s->rr_num < sorted[0] || inf_s->rr_num > sorted[max])
		inf_r->rr_num = sorted[0];
	else
	{
		while (inf_s->rr_num > sorted[i])
			i++;
		inf_r->rr_num = sorted[i];
	}
}

static void	min_rmoves_r(t_dlist *r, t_r *inf_r)
{
	t_dlist	*temp;
	int		rot;

	temp = r;
	rot = 0;
	while (*(int *)temp->content != inf_r->r_num)
	{
		temp = temp->next;
		rot++;
	}
	inf_r->r_rot = rot;
	temp = r;
	rot = 0;
	while (*(int *)temp->content != inf_r->r_num)
	{
		temp = temp->prev;
		rot++;
	}
	inf_r->r_rrot = rot;
}

static void	min_rrmoves_r(t_dlist *r, t_r *inf_r)
{
	t_dlist	*temp;
	int		rot;

	temp = r;
	rot = 0;
	while (*(int *)temp->content != inf_r->rr_num)
	{
		temp = temp->next;
		rot++;
	}
	inf_r->rr_rot = rot;
	temp = r;
	rot = 0;
	while (*(int *)temp->content != inf_r->rr_num)
	{
		temp = temp->prev;
		rot++;
	}
	inf_r->rr_rrot = rot;
}
