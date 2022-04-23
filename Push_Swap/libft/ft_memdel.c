#include "libft.h"

void	ft_memdel(void **mem)
{
	if (mem != NULL)
	{
		free(*mem);
		*mem = NULL;
	}
}
