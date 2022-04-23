#include "libft.h"

/*
**	Free and NULL an array of strings with the last element being NULL-pointer
*/

void	ft_strarray_clear(char ***str_array)
{
	int	i;

	i = -1;
	while ((*str_array)[++i])
		ft_strdel(&(*str_array)[i]);
	free(*str_array);
	*str_array = NULL;
}