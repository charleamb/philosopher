/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:16:14 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/08 19:20:22 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		*reaper(void *in)
{
	t_inst			*s;
	unsigned int	current_time;

	s = (t_inst *)in;
	usleep(s->all->ttd * MILLE);
	current_time = l_heure(s->all->start_usec, s->all->start_sec);
	if (s->philo->life && current_time - s->philo->last_meal >= s->all->ttd)
	{
		sem_wait(s->philo->s_display);
		s->all->sm1die = 1;
		display_manager(s->all, s->philo, EVENT_DEAD);
	}
	return (NULL);
}
