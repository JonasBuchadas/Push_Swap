#include "push_swap.h"

void	sort_medium_size(t_dlist **a)
{
	t_i		inf_a;
	t_i		inf_b;
	t_dlist	*b;

	b = NULL;
	while (ft_cdlstsize(*a) > 3)
	{
		stack_info(*a, &inf_a);
		smart_push_median(a, &b, &inf_a, &inf_b);
	}
	if (ft_cdlstsize(*a) == 3)
		sort_size3(a);
	if (ft_cdlstsize(*a) == 2)
		sort_size2(a);
	while (ft_cdlstsize(b) > 0)
	{	
		stack_info(*a, &inf_a);
		stack_info(b, &inf_b);
		smart_push_a(a, &b, &inf_a, &inf_b);
	}
	ft_cdlstiter(*a, print);
	printf("STACK_A\n");
}

void	stack_info(t_dlist *stack, t_i *inf)
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
