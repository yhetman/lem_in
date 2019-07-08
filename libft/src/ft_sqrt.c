#include "../includes/libft.h"

int		ft_sqrt(int number)
{
	int		root;

	root = 0;
	while (ft_pow(2, root) < number)
		root++;
	return (root);
}
