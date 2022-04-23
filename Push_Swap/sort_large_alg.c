#include "push_swap.h"

void	sort_large_size(t_dlist **a)
{
	t_s		inf_s;
	t_dlist	*b;

	b = NULL;
	inf_s.moves = 0;
	inf_s.print = true;
	while (ft_cdlstsize(*a) > 5)
	{
		stack_info(*a, &inf_s);
		push_median_b(a, &b, &inf_s);
	}
	sort_stack_print(a, &b, &inf_s);
	while (ft_cdlstsize(b) > 0)
	{
		stack_info(b, &inf_s);
		smart_push_median_print(a, &b, &inf_s);
	}
	smart_rotate_a_print(a, min_stack(*a), &inf_s);
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
