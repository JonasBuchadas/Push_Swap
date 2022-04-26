#include "push_swap.h"

static void		check_int(char *s, int *arr, int size);
static void		sort_stack_from_input(t_dlist **a, int fd);
static void		execute_input(t_dlist **a, t_dlist **b, char *line);

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
		sort_stack_from_input(&stack, STDIN_FILENO);
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

static void	sort_stack_from_input(t_dlist **a, int fd)
{
	char	*line;
	int		size;
	t_dlist	*b;

	size = ft_cdlstsize(*a);
	b = NULL;
	line = get_next_line(fd);
	while (line)
	{
		execute_input(a, &b, line);
		free(line);
		line = get_next_line(fd);
	}
	if (is_sorted(*a) && ft_cdlstsize(*a) == size)
		write(1, &"OK\n", 3);
	else
		write(1, &"KO\n", 3);
}

static void	execute_input(t_dlist **a, t_dlist **b, char *line)
{
	if (line[0] == 's' && line[1] == 's')
		ss(a, b, false);
	else if (line[0] == 's' && line[1] == 'a')
		sa(a, false);
	else if (line[0] == 's' && line[1] == 'b')
		sb(b, false);
	else if (line[0] == 'r' && line[1] == 'a')
		ra(a, false);
	else if (line[0] == 'r' && line[1] == 'b')
		rb(b, false);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rra(a, false);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rrb(b, false);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		rrr(a, b, false);
	else if (line[0] == 'r' && line[1] == 'r')
		rr(a, b, false);
	else if (line[0] == 'p' && line[1] == 'a')
		pa(a, b, false);
	else if (line[0] == 'p' && line[1] == 'b')
		pb(a, b, false);
}
