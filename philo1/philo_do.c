/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:38:57 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/05 18:54:10 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		philo_take_fork(t_inst *in, t_phil *philo)
{
	pthread_mutex_lock(philo->m_forkr);
	pthread_mutex_lock(philo->m_forkl);
	pthread_mutex_lock(philo->m_display);
	display_manager(in->all, philo, EVENT_FORK);
	display_manager(in->all, philo, EVENT_FORK);
	pthread_mutex_unlock(philo->m_display);
}

void		philo_eat(t_inst *in, t_phil *philo)
{
	pthread_mutex_lock(philo->m_display);
	display_manager(in->all, philo, EVENT_EAT);
	philo->last_meal = l_heure(in->all->start_usec, in->all->start_sec);
	pthread_mutex_unlock(philo->m_display);
	usleep(in->all->tte * MILLE);
	pthread_mutex_unlock(philo->m_forkr);
	pthread_mutex_unlock(philo->m_forkl);
}

void		philo_sleep(t_inst *in, t_phil *philo)
{
	pthread_mutex_lock(philo->m_display);
	display_manager(in->all, philo, EVENT_SLEEP);
	pthread_mutex_unlock(philo->m_display);
	usleep(in->all->tts * MILLE);
}

void		philo_think(t_inst *in, t_phil *philo)
{
	pthread_mutex_lock(philo->m_display);
	display_manager(in->all, philo, EVENT_THINK);
	pthread_mutex_unlock(philo->m_display);
}
