#include "push_swap.h"

char	**parser(int size, char **strlist)
{
	int		i;
	char	**result;

	if (size == 1)
	{
		result = ft_split(strlist[1], ' ');
		return (result);
	}
	else
	{
		result = (void *)malloc(sizeof(char *) * (size + 1));
		i = -1;
		while (++i < size)
			result[i] = ft_strdup(strlist[i + 1]);
		result[i] = NULL;
	}
	return (result);
}

int	size_strlist(char **strlist)
{
	int	size;

	size = 0;
	while (strlist[size] != 0)
		size++;
	return (size);
}
