#include "../includes/philosophers.h"

int	initialize_mutexes(t_data *vars)
{
	int	i;

	i = 0;
	while (i < vars->count)
	{
		if (pthread_mutex_init(&(vars->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(vars->spaghetti), NULL))
		return (1);
	if (pthread_mutex_init(&(vars->message), NULL))
		return (1);
	return (0);
	
}