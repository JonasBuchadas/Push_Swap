#include "libft.h"

int ft_max_int(int n, ...)
{
    int max;
    int i;
    int temp;
    va_list ptr;

    va_start(ptr, n);
    i = 0;
    max = va_arg(ptr, int);
    while (++i < n)
    {
        temp = va_arg(ptr, int);
        if (temp > max)
            max = temp;
    }
    va_end(ptr);
    return max;
}