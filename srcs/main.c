#include "auto-learning.h"

/*
** usage :
** print the usage of the program
*/

int	usage()
{
	ft_putendl("usage : ./auto_learn [population] [min limit] [max limit] [iteration]");
	return (-1);
}

int	main(int ac, char **av)
{
	t_data data;
	
	if (ac != 5)
		return (usage());
	if (get_params(&data, av) == -1)
	{
		ft_putendl("Bad params.");
		return (usage());
	}
	set_population(&data);
	learn(&data);
	return (1);
}