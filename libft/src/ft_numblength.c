#include "../includes/libft.h"

int		ft_numblength(int number)
{
	int		res;
	int		temp;

	temp = number;
	res = 0;
	while (temp / 10)
	{
		res++;
		temp /= 10;
	}
	return (res);
}
