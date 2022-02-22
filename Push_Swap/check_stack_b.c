#include "push_swap.h"

static void	analyze_b(t_dlist *b, t_i *inf_a, t_ib *inf_b);
static void b_insert_values(int *sorted, int max, t_i *inf_a, t_ib *inf_b);
static void	min_rmoves_b(t_dlist *b, t_ib *inf_b);
static void	min_rrmoves_b(t_dlist *b, t_ib *inf_b);

void	check_stack_b(t_dlist *b, t_i *inf_a, t_ib *inf_b)
{
	if (!b)
	{	
		inf_b->r_rot = 0;
		inf_b->r_rrot = 0;
		inf_b->rr_rot = 0;
		inf_b->rr_rrot = 0;
		return ;
	}
	analyze_b(b, inf_a, inf_b);
	min_rmoves_b(b, inf_b);
	min_rrmoves_b(b, inf_b);
}

static void	analyze_b(t_dlist *b, t_i *inf_a, t_ib *inf_b)
{
	int		*sorted;
	t_dlist	*temp;
	int		i;
	int		size;

	if (!b)
		return ;
	size = ft_cdlstsize(b);
	sorted = (int *)malloc(sizeof(int) * size);
	i = -1;
	temp = b;
	while (temp->next != b)
	{
		sorted[++i] = *(int *)temp->content;
		temp = temp->next;
	}
	sorted[++i] = *(int *)temp->content;
	ft_sort_int_tab(sorted, size);
	b_insert_values(sorted, i,inf_a, inf_b);
	free(sorted);
}

static void b_insert_values(int *sorted, int max, t_i *inf_a, t_ib *inf_b)
{
	int i;

	i = max;
	if (inf_a->r_num < sorted[0] || inf_a->r_num > sorted[max])
		inf_b->r_num = sorted[max];
	else
	{
		while (inf_a->r_num < sorted[i])
			i--;
		inf_b->r_num = sorted[i];
	}
	i = max;
	if (inf_a->rr_num < sorted[0] || inf_a->rr_num > sorted[max])
		inf_b->rr_num = sorted[max];
	else
	{
		while (inf_a->rr_num < sorted[i])
			i--;
		inf_b->rr_num = sorted[i];
	}
}

static void	min_rmoves_b(t_dlist *b, t_ib *inf_b)
{
	t_dlist	*temp;
	int		r;

	temp = b;
	r = 0;
	while (*(int *)temp->content != inf_b->r_num)
	{
		temp = temp->next;
		r++;
	}
	inf_b->r_rot = r;
	temp = b;
	r = 0;
	while (*(int *)temp->content != inf_b->r_num)
	{
		temp = temp->prev;
		r++;
	}
	inf_b->r_rrot = r;
}

static void	min_rrmoves_b(t_dlist *b, t_ib *inf_b)
{
	t_dlist	*temp;
	int		r;

	temp = b;
	r = 0;
	while (*(int *)temp->content != inf_b->rr_num)
	{
		temp = temp->next;
		r++;
	}
	inf_b->rr_rot = r;
	temp = b;
	r = 0;
	while (*(int *)temp->content != inf_b->rr_num)
	{
		temp = temp->prev;
		r++;
	}
	inf_b->rr_rrot = r;
}