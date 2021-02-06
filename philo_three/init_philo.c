/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:13:20 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/10 16:18:01 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	initphilo(t_all *all, t_phil *philo)
{
	unsigned int	i;
	sem_t			*sem_forks;
	sem_t			*sem_display;

	i = 0;
	sem_unlink("fork");
	sem_unlink("display");
	sem_forks = sem_open("fork", O_CREAT | O_EXCL, S_IRWXU, all->nop);
	sem_display = sem_open("display", O_CREAT | O_EXCL, S_IRWXU, 1);
	while (i < all->nop)
	{
		philo[i].s_display = sem_display;
		philo[i].s_fork = sem_forks;
		philo[i].num = i + 1;
		philo[i].last_meal = 0;
		i++;
	}
}
