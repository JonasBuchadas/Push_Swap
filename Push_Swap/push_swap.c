#include "push_swap.h"

static void		check_int(char *s, int *arr, int size);

int	main(int argc, char **argv)
{
	char	**strlist;
	int		size;
	int		*input;
	t_dlist	*stack;
	int		i;

	if (argc == 1)
		return (0);
	strlist = parser(argv);
	size = size_strlist(strlist);
	input = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (size > ++i)
	{
		check_int(strlist[i], input, i);
		input[i] = ft_atoi((const char *)strlist[i]);
	}
	stack = create_stack(input, size);
	if (!is_sorted(stack))
		sort_stack(&stack, input);
	mem_clear(strlist, &stack, input);
	return (0);
}

static void	check_int(char *s, int *arr, int size)
{
	int	n;
	int	i;

	i = -1;
	if (s[0] == '-' && ft_isdigit(s[1]) == 1)
		i++;
	while (s[++i])
	{	
		if (ft_isdigit(s[i]) == 0)
			error();
	}		
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
