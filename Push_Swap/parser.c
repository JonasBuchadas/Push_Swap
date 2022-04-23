#include "push_swap.h"

static int	args_size(char **argv);
static char	**pass_args(char **argv, int size);

char	**parser(char **argv)
{
	int		size;
	char	**result;

	size = args_size(argv);
	result = pass_args(argv, size);
	return (result);
}

int	size_strlist(char **argv)
{
	int	size;

	size = 0;
	while (argv[size] != 0)
		size++;
	return (size);
}

static int	args_size(char **argv)
{
	int		size;
	int		i;
	char	**array;

	i = -1;
	size = 0;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			array = ft_split(argv[i], ' ');
			size += size_strlist(array);
			ft_strarray_clear(&array);
		}	
		else
			size++;
	}
	return (size);
}

static char	**pass_args(char **argv, int size)
{
	int		i;
	int		j;
	int		k;
	char	**array;
	char	**subarray;

	i = 0;
	j = 0;
	array = (void *)malloc(sizeof(char *) * size);
	while (argv[++j])
	{
		if (ft_strchr(argv[j], ' '))
		{
			subarray = ft_split(argv[j], ' ');
			k = -1;
			while (subarray[++k])
				array[i++] = ft_strdup(subarray[k]);
			ft_strarray_clear(&subarray);
		}
		else
			array[i++] = ft_strdup(argv[j]);
	}
	array[size - 1] = '\0';
	return (array);
}
