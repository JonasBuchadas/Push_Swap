#include "push_swap.h"

int	*sort_stack(t_list *stack, info *inf);

void	sort_medium_size(t_list **a)
{
	int		*sorted;
	info	inf;
	t_list	*b;

	sorted = sort_stack(*a, &inf);
	printf("Size of array: %li\n", inf.size);
	smart_2stack_rotate(a, &b, sorted, &inf);
	ft_lstiter(b, print);
	free(sorted);
	return ;
}

int	*sort_stack(t_list *stack, info *inf)
{
	int		*sorted;
	t_list	*temp;
	int		i;
	int		size;

	size = ft_lstsize(stack);
	sorted = (int *)malloc(sizeof(int) * size);
	i = 0;
	temp = stack;
	while (temp)
	{
		sorted[i] = *(int *)temp->content;
		temp = temp->next;
		i++;
	}
	ft_sort_int_tab(sorted, size);
	inf->size = size;
	inf->median = size / 2;
	inf->min = 0;
	inf->max = inf->median;
	inf->size_a = size;
	inf->size_b = 0;
	return (sorted);
}
