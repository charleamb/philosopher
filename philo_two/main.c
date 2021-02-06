/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:03:16 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/10 15:00:35 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*lifephilo(void *in)
{
	unsigned int		i;
	t_inst				*s;
	pthread_t			death;

	i = 0;
	s = (t_inst *)in;
	s->philo->life = 1;
	while (!s->all->sm1die && (!s->all->meals || i < s->all->noe))
	{
		pthread_detach(death);
		pthread_create(&death, NULL, &reaper, s);
		philo_take_fork(s, s->philo);
		philo_eat(s, s->philo);
		philo_sleep(s, s->philo);
		philo_think(s, s->philo);
		i++;
	}
	s->philo->life = 0;
	pthread_detach(death);
	if (s->all->meals && i == s->all->noe)
		s->all->mealfinish++;
	return (NULL);
}

int		gophilo(t_all *all, t_phil *philo, t_inst *in)
{
	unsigned int	i;

	i = 0;
	while (i < all->nop)
	{
		in[i].all = all;
		in[i].philo = &philo[i];
		if (pthread_create(&philo[i].thread, NULL, &lifephilo, &in[i]))
			return (1);
		usleep(10);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_all			all;
	t_phil			*philo;
	t_inst			*in;

	if (!datafilo(ac, av, &all))
		return (0);
	if (!(philo = (t_phil *)malloc(sizeof(t_phil) * (all.nop + 1))))
		return (0);
	if (!(in = (t_inst *)malloc(sizeof(t_inst) * (all.nop + 1))))
		return (0);
	initphilo(&all, philo);
	gophilo(&all, philo, in);
	monitor(&all, philo);
	free(philo);
	free(in);
	return (0);
}
