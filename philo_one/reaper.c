/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:16:14 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/05 19:06:46 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*reaper(void *in)
{
	t_inst			*s;
	unsigned int	current_time;

	s = (t_inst *)in;
	usleep(s->all->ttd * MILLE);
	current_time = l_heure(s->all->start_usec, s->all->start_sec);
	if (s->philo->life && current_time - s->philo->last_meal >= s->all->ttd)
	{
		pthread_mutex_lock(s->philo->m_display);
		s->all->sm1die = 1;
		display_manager(s->all, s->philo, EVENT_DEAD);
	}
	return (NULL);
}
