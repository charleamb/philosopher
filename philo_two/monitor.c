/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:42:14 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/10 14:59:20 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		kill_philoso(t_all *all, t_phil *philo)
{
	unsigned int	i;

	i = 0;
	while (i < all->nop)
	{
		pthread_detach(philo[i].thread);
		i++;
	}
}

void		monitor_die(t_all *all, t_phil *philo)
{
	while (!all->sm1die)
		usleep(MILLE);
	if (all->sm1die)
		kill_philoso(all, philo);
}

void		monitor_meals(t_all *all, t_phil *philo)
{
	while (!all->sm1die && (all->mealfinish < all->nop))
		usleep(MILLE);
	if (all->sm1die || (all->mealfinish == all->nop))
		kill_philoso(all, philo);
	if (!all->sm1die || (all->mealfinish == all->nop))
	{
		sem_wait(philo->s_display);
		display_allmeals(all);
	}
}

void		monitor(t_all *all, t_phil *philo)
{
	if (all->meals)
		monitor_meals(all, philo);
	else
		monitor_die(all, philo);
}
