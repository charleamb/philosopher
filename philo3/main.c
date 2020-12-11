/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:03:16 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/10 16:16:02 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*lifephilo(t_inst *r, t_phil *philo)
{
	unsigned int		i;
	t_all				*s;
	pthread_t			death;

	i = 0;
	s = r->all;
	while (!s->sm1die && (!s->meals || i < s->noe))
	{
		pthread_detach(death);
		pthread_create(&death, NULL, &reaper, r);
		philo_take_fork(r, philo);
		philo_eat(r, philo);
		philo_sleep(r, philo);
		philo_think(r, philo);
		i++;
	}
	pthread_detach(death);
	if (s->sm1die)
		exit(42);
	if (s->meals && i == s->noe)
		s->mealfinish++;
	exit(2);
}

int		gophilo(t_all *all, t_phil *philo)
{
	unsigned int	i;
	t_inst			*r;

	if (!(r = (t_inst *)malloc(sizeof(t_inst))))
		return (0);
	r->all = all;
	i = 0;
	while (i < all->nop)
	{
		r->philo = &philo[i];
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			lifephilo(r, &philo[i]);
		usleep(10);
		i++;
	}
	free(r);
	return (0);
}

int		main(int ac, char **av)
{
	t_all			all;
	t_phil			*philo;

	if (!datafilo(ac, av, &all))
		return (0);
	if (!(philo = (t_phil *)malloc(sizeof(t_phil) * (all.nop))))
		return (0);
	initphilo(&all, philo);
	gophilo(&all, philo);
	monitor(&all, philo);
	free(philo);
	return (0);
}
