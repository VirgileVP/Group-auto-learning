#ifndef AUTO_LEARNING_H
# define AUTO_LEARNING_H
# include "../libft/libft.h"
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_data
{
	int				*population;
	int             quantity;
	int				min;
	int				max;
	float			average;
	int				iteration;
}					t_data;

int	    get_params(t_data *data, char **av);
void	set_population(t_data *data);
void	learn(t_data *data);
void	adjustment(t_data *data, int index, int previous, int next);


#endif