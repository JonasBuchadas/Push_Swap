#include "push_swap.h"

void	sort_medium_size(t_dlist **a)
{
	t_s		inf_s;
	t_r		inf_r;
	t_dlist	*b;
	t_dlist	*temp;

	b = NULL;
	while (ft_cdlstsize(*a) > 3)
	{
		stack_info(*a, &inf_s);
		push_median(a, &b, &inf_s);
	}
	if (ft_cdlstsize(*a) == 3)
		sort_size3(a);
	if (ft_cdlstsize(*a) == 2)
		sort_size2(a);
	while (ft_cdlstsize(b) > 0)
	{
		stack_info(b, &inf_s);
		smart_push_median(a, &b, &inf_s, &inf_r);
	}
	stack_info(*a, &inf_s);
	temp = *a;
	while (*(int *)temp->content != inf_s.min)
	{
		smart_rotate_a(a, inf_s.min);
		temp = *a;
	}	
}

void	stack_info(t_dlist *stack, t_s *inf)
{
	int		*sorted;
	t_dlist	*temp;
	int		i;
	int		size;

	if (!stack)
		return ;
	size = ft_cdlstsize(stack);
	sorted = (int *)malloc(sizeof(int) * size);
	i = 0;
	temp = stack;
	while (temp->next != stack)
	{
		sorted[i] = *(int *)temp->content;
		temp = temp->next;
		i++;
	}
	sorted[i] = *(int *)temp->content;
	ft_sort_int_tab(sorted, size);
	inf->size = size;
	inf->median = sorted[size / 2];
	inf->min = sorted[0];
	inf->max = sorted[size - 1];
	free(sorted);
}
