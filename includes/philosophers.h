#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/wait.h>

# define ERRMSG "philo: ./philo [philosophers] [time to die] [time to eat] [time to sleep] [times each philosopher must eat]\n"

typedef struct s_philo
{
	int		eat_num;
	int		position;
	char	*position_str;
	int		fork1;
	int		fork2;


}	t_philo;

typedef struct s_data
{
	int				count;
	int				tt_sleep;
	int 			tt_die;
	int				tt_eat;
	int 			mx_eat;
	unsigned long	tt_start;
	int				abort_cond;
	pthread_mutex_t write;
	t_philo			*philos;
	pthread_mutex_t *forks;
	pthread_mutex_t spaghetti;
	pthread_mutex_t message;

}	t_data;


int return_error(char *error);
int	is_int(char *arg);
int	ft_atoi(const char *str);
int	ft_strlen(char *str);
int	valid_args(int argc, char **argv, t_data *v);


#endif