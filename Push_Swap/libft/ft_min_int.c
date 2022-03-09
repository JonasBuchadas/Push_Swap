#include "libft.h"

int	ft_min_int(int n, ...)
{
	int		min;
	int		i;
	int		temp;
	va_list	ptr;

	va_start(ptr, n);
	i = 0;
	min = va_arg(ptr, int);
	while (++i < n)
	{
		temp = va_arg(ptr, int);
		if (temp < min)
			min = temp;
	}
	va_end(ptr);
	return (min);
}
