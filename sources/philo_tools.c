/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 06:39:57 by azaher            #+#    #+#             */
/*   Updated: 2023/06/24 15:22:55 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_printmsg(char *message, t_philo *philo, int locknum)
{
	char	*time;

	pthread_mutex_lock(&philo->vars->message);
	time = ft_itoa(fetch_time() - philo->vars->tt_start);
	if (!philo->vars->abort_cond && !philo->vars->count_mx_eat)
		printf("%s %s %s\n", time, philo->position_str, message);
	if (!locknum)
		pthread_mutex_unlock(&philo->vars->message);
	free(time);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->forks[philo->fork1]);
	philo_printmsg("has taken a fork", philo, 0);
	pthread_mutex_lock(&philo->vars->forks[philo->fork2]);
	philo_printmsg("has taken a fork", philo, 0);
	pthread_mutex_lock(&philo->vars->spaghetti);
	philo_printmsg("is eating", philo, 0);
	pthread_mutex_unlock(&philo->vars->spaghetti);
	philo->last_meal = fetch_time();
	my_sleep(philo->vars->tt_eat, philo->vars);
	philo->eat_num++;
	pthread_mutex_unlock(&philo->vars->forks[philo->fork1]);
	pthread_mutex_unlock(&philo->vars->forks[philo->fork2]);
}

void	philo_death(t_data *vars, t_philo *philo)
{
	int	i;

	while (!vars->count_mx_eat)
	{
		i = 0;
		while (i < vars->count && !vars->abort_cond)
		{
			pthread_mutex_lock(&vars->spaghetti);
			if ((int)(fetch_time() - philo[i].last_meal) >= vars->tt_die)
			{
				philo_printmsg("died", &philo[i], 1);
				vars->abort_cond = 1;
			}
			pthread_mutex_unlock(&vars->spaghetti);
			i++;
		}
		if (vars->abort_cond)
			break ;
		vars->count_mx_eat = (i == vars->count);
	}
}

void	thread_destroy(t_data *vars)
{
	int	i;

	if (vars->count == 1)
		pthread_detach(vars->philos[0].id);
	else
	{
		i = -1;
		while (++i < vars->count)
			pthread_join(vars->philos[i].id, NULL);
	}
	i = -1;
	while (++i < vars->count)
		pthread_mutex_destroy(&vars->forks[i]);
	pthread_mutex_destroy(&vars->spaghetti);
	pthread_mutex_destroy(&vars->message);
	i = -1;
	while (++i < vars->count)
		free(vars->philos[i].position_str);
	free(vars->philos);
	free(vars->forks);
}
