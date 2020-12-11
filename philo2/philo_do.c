/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:38:57 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/08 19:34:19 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		philo_take_fork(t_inst *in, t_phil *philo)
{
	sem_wait(philo->s_fork);
	sem_wait(philo->s_fork);
	sem_wait(philo->s_display);
	display_manager(in->all, philo, EVENT_FORK);
	display_manager(in->all, philo, EVENT_FORK);
	sem_post(philo->s_display);
}

void		philo_eat(t_inst *in, t_phil *philo)
{
	sem_wait(philo->s_display);
	display_manager(in->all, philo, EVENT_EAT);
	philo->last_meal = l_heure(in->all->start_usec, in->all->start_sec);
	sem_post(philo->s_display);
	usleep(in->all->tte * MILLE);
	sem_post(philo->s_fork);
	sem_post(philo->s_fork);
}

void		philo_sleep(t_inst *in, t_phil *philo)
{
	sem_wait(philo->s_display);
	display_manager(in->all, philo, EVENT_SLEEP);
	sem_post(philo->s_display);
	usleep(in->all->tts * MILLE);
}

void		philo_think(t_inst *in, t_phil *philo)
{
	sem_wait(philo->s_display);
	display_manager(in->all, philo, EVENT_THINK);
	sem_post(philo->s_display);
}
