#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = ft_memalloc(sizeof(t_stack));
	b = ft_memalloc(sizeof(t_stack));
	if (!initialize_stack(a, ac, av))
	{
		FP("Error : INVALID INPUT\n");
		return (0);
	}
	if (!read_dispatcher(a, b))
		return (0);
	if (is_empty(b) && check_sorted(a))
		FP("OK\n");
	else
		FP("KO\n");
	free_stack(a);
	return (0);
}
