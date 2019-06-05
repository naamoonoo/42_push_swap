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
	if (check_sorted(a, a->cnt) && is_empty(b))
		return (0);
	if (a->cnt <= 5)
		sort_only_5(a, b);
	else
		split_a(a, b, a->cnt);
		// split_sort(a, b, a->cnt);


	// sort_3(a, b);
	// while (!is_empty(b))
	// 	DP(a, b, "pa");
	// do sort!!!!
	// DP(&a, &s
	// // FP("first input %d\t last input %d\n", a.last->data, a.top->data);
	// FP("sa\npb\npb\npb\nsa\npa\npa\npa\n");
	// FP("%s\n", check_sorted(a) ? "OK" : "KO");
	// FP("a show!\n");
	// show(a);
	// FP("b show!\n");
	// show(b);
	free_stack(a);
	// while (1)
	// 	sleep(1);
	return (0);
}

