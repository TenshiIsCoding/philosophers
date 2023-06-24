/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 02:23:44 by azaher            #+#    #+#             */
/*   Updated: 2023/06/16 02:23:44 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

unsigned long	fetch_time(void)
{
	struct timeval	tstruct;
	unsigned long	ret;

	gettimeofday(&tstruct, NULL);
	ret = (tstruct.tv_sec * (unsigned long)1000) + (tstruct.tv_usec / 1000);
	return (ret);
}