void	ft_sort_int_tab(int *tab, int size)
{
	int	rep;
	int	swap;
	int	temp;

	rep = 0;
	swap = 0;
	while (rep < size - 1)
	{
		while (swap < size - rep - 1)
		{
			if (*(tab + swap) > *(tab + swap + 1))
			{
				temp = *(tab + swap);
				*(tab + swap) = *(tab + swap + 1);
				*(tab + swap + 1) = temp;
			}
			swap++;
		}
		swap = 0;
		rep++;
	}
}
