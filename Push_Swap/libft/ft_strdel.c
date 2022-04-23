#include "libft.h"

void	ft_strdel(char **str)
{
	if (str != NULL && *str != NULL)
		ft_memdel((void **)str);
}