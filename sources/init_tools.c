#include "../includes/philosophers.h"

unsigned long  fetch_time()
{
	struct timeval	tstruct;
	unsigned long	ret;

	gettimeofday(&tstruct, NULL);
	ret = (tstruct.tv_sec * (unsigned long)1000) + (tstruct.tv_usec / 1000);
	return (ret);
}