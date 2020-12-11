/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_le_temps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:21:32 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/04 15:35:26 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	l_heure(unsigned int start_usec, unsigned int start_sec)
{
	struct timeval	current_time;
	int				sec;

	gettimeofday(&current_time, NULL);
	sec = current_time.tv_sec - start_sec;
	return (((unsigned int)(sec * 1000000 + current_time.tv_usec) - start_usec)
	/ MILLE);
}

unsigned int	startime(int time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (time == 0)
		return (current_time.tv_usec);
	else
		return (current_time.tv_sec);
	return (0);
}
