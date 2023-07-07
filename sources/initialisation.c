/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 02:22:58 by azaher            #+#    #+#             */
/*   Updated: 2023/06/16 02:22:58 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		vars->philos[i].fork1 = i;
		vars->philos[i].fork2 = (i + 1) % vars->count;
		vars->philos[i].eat_num = 0;
		vars->philos[i].position = i + 1;
		vars->philos[i].position_str = ft_itoa(i + 1);
		vars->philos[i].vars = vars;
		i++;
	}
	if (i != vars->count)
	{
		while (i >= 0)
			free(vars->philos[i--].position_str);
		return (1);
	}
	return (0);
}

void	my_sleep(unsigned long duration, t_data *vars)
{
	unsigned long	depart;

	depart = fetch_time();
	while (!vars->abort_cond)
	{
		if (fetch_time() - depart >= duration)
			break ;
		usleep(50);
	}
}

void	*routine(void *philo)
{
	t_data	*vars;
	t_philo	*philos;
	int		i;

	philos = (t_philo *)philo;
	vars = philos->vars;
	i = 0;
	if (philos->position % 2 && vars->count > 1)
		my_sleep(vars->tt_eat, vars);
	while (!vars->abort_cond && !vars->mx_eat)
	{
		philo_eat(philos);
		philo_printmsg("is sleeping", philos, 0);
		my_sleep(vars->tt_sleep, vars);
		philo_printmsg("is thinking", philos, 0);
	}
	return (NULL);
}

int	start_philosophers(t_data *vars)
{
	int	i;

	i = 0;
	vars->tt_start = fetch_time();
	while (i < vars->count)
	{
		vars->philos[i].last_meal = fetch_time();
		if (pthread_create(&vars->philos[i].id, NULL, routine,
				&(vars->philos[i])))
			return (1);
		i++;
	}
	philo_death(vars, vars->philos);
	pthread_mutex_unlock(&vars->message);
	thread_destroy(vars);
	return (0);
}
