/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:42:14 by chgilber          #+#    #+#             */
/*   Updated: 2021/02/04 14:56:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		kill_philoso(t_all *all, t_phil *philo)
{
	unsigned int	i;

	i = 0;
	while (i < all->nop)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
}

int			check(t_all *all, t_phil *philo)
{
	unsigned int	i;
	int				status;
	int				exitv;

	i = 0;
	while (i < all->nop)
	{
		waitpid(philo[i].pid, &status, WNOHANG);
		if (WIFEXITED(status))
			exitv = WEXITSTATUS(status);
		if (exitv == 42)
		{
			all->sm1die = 1;
			return (1);
		}
		else if (exitv == 2)
		{
			all->mealfinish++;
			i++;
		}
		else
			return (1);
	}
	return (0);
}

void		monitor_die(t_all *all, t_phil *philo)
{
	while (!all->sm1die)
	{
		if (check(all, philo))
			break ;
		usleep(MILLE);
	}
	if (all->sm1die)
		kill_philoso(all, philo);
}

void		monitor_meals(t_all *all, t_phil *philo)
{
	while (!all->sm1die && (all->mealfinish < all->nop))
	{
		if (check(all, philo))
			break ;
		usleep(MILLE);
	}
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
