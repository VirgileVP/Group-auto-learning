#include "auto-learning.h"

/*
** get_params :
** get params from program arguments and put it in the struct
*/

int	get_params(t_data *data, char **av)
{
	data->quantity = ft_atoi(av[1]);
	data->population = ft_memalloc(sizeof(int) * data->quantity + 1);
	data->min = ft_atoi(av[2]);
	data->max = ft_atoi(av[3]);
	data->algo = ft_atoi(av[5]);
	if (data->algo < 1 || data->algo > 2)
		return (-1);
	data->average = 0;
	data->iteration = ft_atoi(av[4]);
	if (data->min >= data->max)
		return (-1);
	return (1);
}

/*
** set_population :
** set all values in struct at default
*/

void	set_population(t_data *data)
{
	time_t	t;
	int		sum = 0;
	int		index = 0;

	srand((unsigned) time(&t));
	while (index < data->quantity)
	{
		data->population[index] = data->min + rand() % data->max;
		sum = sum + data->population[index];
		// printf("%d / ", data->population[index]);
		index++;
	}
	data->average = (float)sum / (float)data->quantity;
}
