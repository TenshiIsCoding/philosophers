#include "../includes/philosophers.h"

static int	ft_countdigits(int n)
{
	int			count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
			count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*asc;
	long long	nb;
	int			len;

	nb = n;
	len = ft_countdigits(n);
	asc = malloc((len + 1) * sizeof(char));
	if (!asc)
		return (0);
	asc[len] = '\0';
	len--;
	if (n == 0)
		asc[0] = '0';
	if (nb < 0)
	{
		asc[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		asc[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	return (asc);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	size_t	nbr;

	i = 0;
	s = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		if (nbr > 9223372036854775807 && s == 1)
			return (-1);
		else if (nbr > 9223372036854775807 && s == -1)
			return (0);
		i++;
	}
	return (nbr * s);
}
