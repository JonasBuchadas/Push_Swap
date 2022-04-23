#include "push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	del(void *num)
{
	*((int *)num) = 0;
}

void	mem_clear(char **strlist, t_dlist **stack, int *input)
{
	ft_strarray_clear(&strlist);
	ft_cdlstclear(stack, &del);
	free(input);
}

t_dlist	*create_stack(int *input, int size)
{
	int		i;
	t_dlist	*stack;
	t_dlist	*temp;

	i = 0;
	stack = ft_cdlstnew(&input[i]);
	while (++i < size)
	{
		temp = ft_cdlstnew(&input[i]);
		ft_cdlstadd_back(&stack, temp);
	}
	return (stack);
}

void	smart_rotate_a(t_dlist **stack, int n)
{
	int		size;
	int		steps;
	t_dlist	*temp;

	size = ft_cdlstsize(*stack);
	temp = *stack;
	steps = 0;
	while (*(int *)(temp)->content != n)
	{
		steps++;
		temp = temp->next;
	}
	if (steps > (size / 2))
	{
		while (*(int *)(*stack)->content != n)
			rra(stack, true);
	}
	else
	{	
		while (*(int *)(*stack)->content != n)
			ra(stack, true);
	}
}
