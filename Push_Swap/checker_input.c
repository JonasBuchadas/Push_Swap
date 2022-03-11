#include "checker.h"

static void execute_input(t_dlist **a, t_dlist **b, char *line);

void sort_stack_from_input(t_dlist **a, int fd)
{
    char    *line;
    int     size;
    t_dlist *b;

    size = ft_cdlstsize(*a);
    b = NULL;
    line = gnl(fd);
    while (line)
    {
        execute_input(a, &b, line);
        line = gnl(fd);
    }
    if (is_sorted(a) && ft_cdlstsize(*a) == size)
        write(1, &"OK\n", 4);
    else
        write(1, &"KO\n", 4);
}

static void execute_input(t_dlist **a, t_dlist **b, char *line)
{
    if (line[0] == 's' && line[1] == 'a')
		sa(a);
	else if (line[0] == 's' && line[1] == 'b')
		sb(b);
	else if (line[0] == 'r' && line[1] == 'a')
		ra(a);
	else if (line[0] == 'r' && line[1] == 'b')
		rb(b);
	else if (line[0] == 'r' && line[1] == 'r')
		rr(a, b);
	else if (line[0] == 'p' && line[1] == 'a')
		pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b')
		pb(a, b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rra(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rrb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		rrr(a, b);
}
