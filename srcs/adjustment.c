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

/*
** adjustment :
** adjust all values depending neighbour's values
*/

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

void	adjustment_v2(t_data *data, int index)
{
	int	sum;
	int	n_inf2;
	int	n_inf1;
	int	n_plus1;
	int	n_plus2;

	sum = 0;
	n_inf1 = data->population[get_previous_neighbour(data, index)];
	n_inf2 = data->population[get_previous_neighbour(data, n_inf1)];
	n_plus1 = data->population[get_next_neighbour(data, index)];
	n_plus2 = data->population[get_next_neighbour(data, n_plus1)];
	sum = n_inf1 + n_inf2 + n_plus1 + n_plus2;
	data->population[index] = sum / 4;
}
