#include "push_swap.h"

static void		check_int(char *s, int *arr, int size);
static t_dlist	*create_stack(int *input, int size);

int	main(int argc, char **argv)
{
	char	**strlist;
	int		size;
	int		*input;
	t_dlist	*stack;
	int		i;

	if (argc == 1)
		exit(1);
	strlist = parser(argc - 1, argv);
	size = size_strlist(strlist);
	if (size < 2)
		error();
	input = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (size > ++i)
	{
		check_int(strlist[i], input, i);
		input[i] = ft_atoi((const char *)strlist[i]);
	}
	stack = create_stack(input, size);
	if (!is_sorted(stack))
		sort_stack(&stack);
	mem_clear(strlist, &stack, input);
	return (0);
}

static void	check_int(char *s, int *arr, int size)
{
	int	n;
	int	i;

	n = ft_atoi((const char *)s);
	if (n == 0 && ft_strncmp(s, "0", 1) != 0)
		error();
	i = -1;
	while (i++ < size - 1)
	{
		if (n == arr[i])
			error();
	}
}

static t_dlist	*create_stack(int *input, int size)
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
