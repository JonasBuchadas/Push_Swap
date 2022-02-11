#include "push_swap.h"

void	sort_medium_size(dt_list **a)
{
	t_i	inf_a;
	t_i	inf_b;
	dt_list	*b;
	
	stack_info(*a, &inf_a);
	smart_2stack_rotate(a, &b, &inf_a, &inf_b);
//	ft_lstiter(b, print);
	return ;
}

void	stack_info(dt_list *stack, t_i *inf)
{
	int		*sorted;
	dt_list	*temp;
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
}
