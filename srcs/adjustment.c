#include "auto-learning.h"

static void	lower_of_the_previous(t_data *data, int index, int previous)
{
	(void)previous;
	data->population[index]++;
}

static void	upper_of_the_previous(t_data *data, int index, int previous)
{
	(void)previous;
	data->population[index]--;
}

static void	lower_of_the_next(t_data *data, int index, int next)
{
	(void)next;
	data->population[index]++;
}

static void	upper_of_the_next(t_data *data, int index, int next)
{
	(void)next;
	data->population[index]--;
}

void	adjustment(t_data *data, int index, int previous, int next)
{
	if (abs(data->population[index] - data->population[previous]) < abs(data->population[index] - data->population[next]))
	{
		if (data->population[index] < data->population[previous])
			lower_of_the_previous(data, index, previous);
		else if (data->population[index] > data->population[previous])
			upper_of_the_previous(data, index, previous);
	}
	else if (abs(data->population[index] - data->population[previous]) > abs(data->population[index] - data->population[next]))
	{
		if (data->population[index] < data->population[next])
			lower_of_the_next(data, index, next);
		else if (data->population[index] > data->population[next])
			upper_of_the_next(data, index, next);
	}
	else if (data->population[previous] == data->population[next])
	{
		if (data->population[index] < data->population[previous])
			lower_of_the_previous(data, index, previous);
		else if (data->population[index] > data->population[previous])
			upper_of_the_previous(data, index, previous);
	}	
}
