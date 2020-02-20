#include "auto-learning.h"

/*
** get_previosu_neighbour :
** return value of previous person
*/

int		get_previous_neighbour(t_data *data, int actual)
{
	if (actual == 0)
		return (data->quantity - 1);
	return (actual - 1);
}

/*
** get_next_neighbour :
** return value of next person
*/

int	get_next_neighbour(t_data *data, int actual)
{
	if (actual == data->quantity - 1)
		return (0);
	return (actual + 1);
}