#include "push_swap.h"

void	initialize_stack(t_stack *s, int ac, char *av[])
{
	s->top = NULL;
	while (--ac)
	{
		// over the int value , less than int value
		// non numeric value

		if (!ft_atoi(av[ac]) && ft_strcmp(av[ac], "0"))
		//  ||
		// (ft_atoi(av[ac]) < INT_MIN || ft_atoi(av[ac]) > INT_MAX))
		{
			{
				FP("ERROR");
				exit(0);
			}
		}
		else
			push(s, ft_atoi(av[ac]));
	}
}

int	main(int ac, char *av[])
{

	t_stack	a;
	t_stack	b;
	initialize_stack(&a, ac, av);
	a.top = NULL;
	b.top = NULL;
	// DP(&a, &s
	// // FP("first input %d\t last input %d\n", a.last->data, a.top->data);
	DP(&a, &b, "sa");
	DP(&a, &b, "pb");
	DP(&a, &b, "pb");
	DP(&a, &b, "pb");
	// DP(&a, &b, "ra");
	// DP(&a, &b, "rb");
	// DP(&a, &b, "rra");
	// DP(&a, &b, "rrb");
	DP(&a, &b, "sa");
	DP(&a, &b, "pa");
	DP(&a, &b, "pa");
	DP(&a, &b, "pa");

	// DP(&a, &b, "rra");
	// DP(&a, &b, "pb");
	// DP(&a, &b, "sa");
	// DP(&a, &b, "rra");
	// DP(&a, &b, "pa");

	FP("%s\n", check_sorted(&a, &b) ? "OK" : "KO");
	FP("a show!\n");
	show(&a);
	FP("b show!\n");
	show(&b);

	// while (1)
	// 	sleep(1);
	return (0);
}
