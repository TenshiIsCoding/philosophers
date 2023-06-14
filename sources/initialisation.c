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

int	initialize_philosophers(t_data *vars)
{
	int	i;

	i = 0;
	while (i < vars->count)
	{
		vars->philos[i].vars = vars;
		vars->philos[i].fork1 = i;
		vars->philos[i].fork2 = (i + 1) % vars->count;
		vars->philos[i].eat_num = 0;
		vars->philos[i].position = i + 1;
		vars->philos[i].position_str = ft_itoa(i + 1);
		i++;
	}
	if (i != vars->count)
	{
		while (i >= 0)
		{
			free(vars->philos[i].position_str);
			i--;
		}
		return (1);
	}
	return (0);
}

void	*routine(void *philo)
{
	t_data	*vars;
	t_philo	*philos;
	int i;

	vars = philos->vars;
	philos = (t_philo *)philo;
	i = 0;
	if (philos->position % 2 && vars->count	> 1)
		

}

int	start_philosophers(char **argv, t_data *vars)
{
	int	i;

	i = 0;
	vars->tt_start = fetch_time();
	while(i < vars->count)
	{
		vars->philos[i].last_meal = fetch_time();
		if (pthread_create(&vars->philos[i], NULL, routine, &(vars->philos[i])))

		i++;
	}
}