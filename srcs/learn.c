#include "auto-learning.h"

/*
** print_value :
** print average value and all population values
*/

static void print_values(t_data *data)
{
	int	index = 0;

	ft_putstr("average value = ");
	printf("%f", data->average);
	fflush(stdout);
	ft_putchar('\n');
	ft_putendl("Population values :");
	while (index < data->quantity)
	{
		printf("%2d ", data->population[index]);
		fflush(stdout);
		// ft_putnbr(data->population[index]);
		// ft_putchar('|');
		index++;
	}
	ft_putchar('\n');
}

/*
** learn :
** browse the population and launch the adjustment function for each people
*/

void	learn(t_data *data)
{
	int	index = 0;
	int	loop = 0;
	int	next_neighbour = 0;
	int	previous_neighbour = 0;
	int	sum = 0;

	print_values(data);
	while (loop < data->iteration)
	{
		while (index < data->quantity)
		{
			sum = sum + data->population[index];
			previous_neighbour = get_previous_neighbour(data, index);
			next_neighbour = get_next_neighbour(data, index);
			if (data->algo == 1)
				adjustment(data, index, previous_neighbour, next_neighbour);
			else
				adjustment_v2(data, index);
			index++;
		}
		index = 0;
		data->average = (float)sum / (float)data->quantity;
		sum = 0;
		print_values(data);
		usleep(10000);
		loop++;
	}

	printf("\n\nFINAL AVERAGE = %f\n", data->average);
}