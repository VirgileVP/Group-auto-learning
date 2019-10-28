#include "auto-learning.h"

static void print_values(t_data *data)
{
	//int	index = 0;

	ft_putstr("average value = ");
	printf("%f", data->average);
	fflush(stdout);
	/*ft_putchar('\n');
	ft_putendl("Population values :");
	while (index < data->quantity)
	{
		printf("%2d ", data->population[index]);
		fflush(stdout);
		// ft_putnbr(data->population[index]);
		// ft_putchar('|');
		index++;
	}*/
	ft_putchar('\n');
}

static int	set_previous_neighbour(t_data *data, int actual, int previous)
{
	if (actual == 0)
		previous = data->quantity - 1;
	if (actual == data->quantity - 1)
		previous = actual - 1;
	return (previous);
}

static int	set_next_neighbour(t_data *data, int actual, int next)
{
	if (actual == 0)
		next = actual + 1;
	if (actual == data->quantity - 1)
		next = 0;
	return (next);
}

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
			previous_neighbour = set_previous_neighbour(data, index, previous_neighbour);
			next_neighbour = set_next_neighbour(data, index, next_neighbour);
			adjustment(data, index, previous_neighbour, next_neighbour);
			index++;
		}
		index = 0;
		data->average = (float)sum / (float)data->quantity;
		sum = 0;
		print_values(data);
		//usleep(10000);
		loop++;
	}

	printf("\n\nFINAL AVERAGE = %f\n", data->average);
}