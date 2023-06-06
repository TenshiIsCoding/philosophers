#include "includes/philosophers.h"

int	initialize_values(t_data *vars)
{
	vars->philos = malloc(vars->count * sizeof(t_philo));
	if (!vars->philos)
		return (1);
	vars->forks = malloc(vars->count * sizeof(pthread_mutex_t));
	if (!vars->forks)
	{
		free(vars->philos);
		return (1);
	}
	if (initialize_mutexes(vars))
	{
		(free(vars->philos),free(vars->forks));
		return (1);
	}
	
}

int main(int argc, char **argv)
{
	t_data	vars;

	if (argc < 5 || argc > 6)
		return (return_error(ERRMSG));
	if (valid_args(argc, argv, &vars))
		return (return_error("philo: Invalid arguments. \n"));
	if (initialize_values(&vars))
		return(return_error("philo: Error in initialization. \n"));
	if (initialize_philosophers)
	
}
