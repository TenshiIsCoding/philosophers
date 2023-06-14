#include "../includes/philosophers.h"

int	is_int(char *arg)
{
	int		i;
	int		sign;
	long	value;

	i = 0;
	sign = 0;
	value = 0;
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] >= 13))
		i++;
	if (arg[i] == '-')
		sign = 1;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] && (arg[i] >= 48 && arg[i] <= 57))
	{
		if (value > 214748364 || (value == 214748364
				&& ((!sign && arg[i] - 48 > 7) || (sign && arg[i] - 48 > 8))))
				return (1);
		else
			value = (value * 10) + arg[i++] - 48;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int return_error(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

int	valid_args(int argc, char **argv, t_data *v)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_int(argv[i]) || ft_atoi(argv[i]) < 0)
			return (1);
		i++;
	}
	v->count = ft_atoi(argv[1]);
	v->tt_die = ft_atoi(argv[2]);
	v->tt_eat = ft_atoi(argv[3]);
	v->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		v->mx_eat = ft_atoi(argv[5]);
	else
		v->mx_eat = 0;
	if (v->count < 1 || v->tt_die < 0 || v->tt_eat < 0 
		|| v->tt_sleep < 0 || v->mx_eat < 0)
	return (0);
}

