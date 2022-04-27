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

	if (argc > 1)
	{
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
		sort_stack_from_input(&stack, STDIN_FILENO);
		mem_clear(strlist, &stack, input);
	}
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
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		execute_input(a, &b, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_cdlstclear(&b, &del);
	if (is_sorted(*a) && ft_cdlstsize(*a) == size)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

static void	execute_input(t_dlist **a, t_dlist **b, char *line)
{
	if (ft_strequal("ss\n", line))
		ss(a, b, false);
	else if (ft_strequal("sa\n", line))
		sa(a, false);
	else if (ft_strequal("sb\n", line))
		sb(b, false);
	else if (ft_strequal("ra\n", line))
		ra(a, false);
	else if (ft_strequal("rb\n", line))
		rb(b, false);
	else if (ft_strequal("rra\n", line))
		rra(a, false);
	else if (ft_strequal("rrb\n", line))
		rrb(b, false);
	else if (ft_strequal("rrr\n", line))
		rrr(a, b, false);
	else if (ft_strequal("rr\n", line))
		rr(a, b, false);
	else if (ft_strequal("pa\n", line))
		pa(a, b, false);
	else if (ft_strequal("pb\n", line))
		pb(a, b, false);
	else
		error();
}
