/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:26:19 by azaher            #+#    #+#             */
/*   Updated: 2023/06/17 03:26:19 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define ERRMSG "philo: ./philo [philosophers] [time to die] [time to eat] \
 [time to sleep] [how many times shoul a philosopher eat]\n"

typedef struct s_philo
{
	struct s_data	*vars;	
	unsigned long	last_meal;
	int				eat_num;
	int				position;
	char			*position_str;
	int				fork1;
	int				fork2;
	pthread_t		id;
}	t_philo;

typedef struct s_data
{
	int				count;
	int				tt_sleep;
	int				tt_die;
	int				tt_eat;
	int				mx_eat;
	int				count_mx_eat;
	unsigned long	tt_start;
	int				abort_cond;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	spaghetti;
	pthread_mutex_t	message;

}	t_data;

void			philo_printmsg(char *message, t_philo *philo, int locknum);
void			philo_death(t_data *vars, t_philo *philo);
void			philo_eat(t_philo *philo);
void			thread_destroy(t_data *vars);
int				return_error(char *error);
int				is_int(char *arg);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_strlen(char *str);
int				valid_args(int argc, char **argv, t_data *v);
int				initialize_mutexes(t_data *vars);
int				initialize_philosophers(t_data *vars);
int				start_philosophers(t_data *vars);
void			my_sleep(unsigned long duration, t_data *vars);
unsigned long	fetch_time(void);

#endif