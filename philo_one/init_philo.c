/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:13:20 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/05 19:30:27 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	init_mutex_fork(t_phil *philo, t_all *all)
{
	unsigned int i;

	i = 0;
	while (i < all->nop)
	{
		philo[i].m_forkr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (philo[i].m_forkr == NULL)
			return ;
		pthread_mutex_init(philo[i].m_forkr, NULL);
		i++;
	}
	i = 0;
	while (i < all->nop)
	{
		if (i == all->nop - 1)
			philo[i].m_forkl = philo[0].m_forkr;
		else
			philo[i].m_forkl = philo[i + 1].m_forkr;
		i++;
	}
}

void	init_mutex_display(t_phil *philo, t_all *all)
{
	unsigned int	i;
	pthread_mutex_t	*display;

	i = 0;
	if (!(display = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
		return ;
	pthread_mutex_init(display, NULL);
	while (i < all->nop)
	{
		philo[i].m_display = display;
		i++;
	}
}

void	initphilo(t_all *all, t_phil *philo)
{
	unsigned int	i;

	i = 0;
	init_mutex_fork(philo, all);
	init_mutex_display(philo, all);
	while (i < all->nop)
	{
		philo[i].num = i + 1;
		philo[i].life = 1;
		philo[i].last_meal = 0;
		i++;
	}
}
