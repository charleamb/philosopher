/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:16:14 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/10 13:54:30 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		*reaper(void *in)
{
	t_inst			*s;
	unsigned int	current_time;

	s = (t_inst *)in;
	usleep(s->all->ttd * MILLE);
	current_time = l_heure(s->all->start_usec, s->all->start_sec);
	if (current_time - s->philo->last_meal >= s->all->ttd)
	{
		sem_wait(s->philo->s_display);
		s->all->sm1die = 1;
		display_manager(s->all, s->philo, EVENT_DEAD);
		exit(42);
	}
	return (NULL);
}
