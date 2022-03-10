#include "push_swap.h"

void	error(void)
{
	write(2, &"Error\n", 7);
	exit(1);
}

void	del(void *num)
{
	*((int *)num) = 0;
}

void	print(void *num)
{
	printf("%i\n", *((int *)num));
}

void	mem_clear(char **strlist, t_dlist **stack, int *input)
{
	int	i;

	i = -1;
	while (strlist[++i] != NULL)
		free(strlist[i]);
	free(strlist[i]);
	free(strlist);
	ft_cdlstclear(stack, &del);
	free(input);
}
