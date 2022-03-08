#include "push_swap.h"

void	sort_medium_size(t_dlist **a)
{
	t_s		inf_s;
	t_r		inf_r;
	t_dlist	*b;

	b = NULL;
	inf_s.partitions = 3;
	inf_s.size = ft_cdlstsize(*a);
	inf_s.part_size = inf_s.size / inf_s.partitions;
	while (ft_cdlstsize(*a) > 5)
	{
		stack_info_partition(*a, &inf_s);
		push_partition(a, &b, &inf_s);
	}
	stack_info_partition(*a, &inf_s);
	sort_stack(a, inf_s.size);
	while (ft_cdlstsize(b) > 0)
	{
		stack_info_partition(b, &inf_s);
		smart_push_median(a, &b, &inf_s, &inf_r);
	}
	stack_info_partition(*a, &inf_s);
	smart_rotate_a(a, inf_s.min);
}

void	stack_info_partition(t_dlist *stack, t_s *inf)
{
	int		*sorted;
	t_dlist	*temp;
	int		i;

	if (!stack)
		return ;
	inf->size = ft_cdlstsize(stack);
	sorted = (int *)malloc(sizeof(int) * inf->size);
	i = 0;
	temp = stack;
	while (temp->next != stack)
	{
		sorted[i] = *(int *)temp->content;
		temp = temp->next;
		i++;
	}
	sorted[i] = *(int *)temp->content;
	ft_sort_int_tab(sorted, inf->size);
	if (inf->part_size > inf->size - 5)
		inf->median = sorted[inf->part_size - 5];
	else if (inf->size > inf->part_size)
		inf->median = sorted[inf->part_size];
	else
		inf->median = sorted[inf->size - 1];
	inf->min = sorted[0];
	inf->max = sorted[inf->size - 1];
	free(sorted);
}
