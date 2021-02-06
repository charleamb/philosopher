/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:15:47 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/10 16:19:11 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include "../incs/philo.h"
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef	struct	s_phil
{
	pthread_t				thread;
	int						num;
	sem_t					*s_fork;
	sem_t					*s_display;
	unsigned int			last_meal;
	int						pid;
}				t_phil;

typedef struct	s_inst
{
	t_phil		*philo;
	t_all		*all;
}				t_inst;

void			initphilo(t_all *all, t_phil *philo);
void			display_allmeals(t_all *all);
void			philo_eat(t_inst *all, t_phil *philo);
void			philo_take_fork(t_inst *all, t_phil *philo);
void			philo_sleep(t_inst *all, t_phil *philo);
void			philo_think(t_inst *all, t_phil *philo);
void			monitor(t_all *all, t_phil *philo);
void			monitor_die(t_all *all, t_phil *philo);
void			display_manager(t_all *s, t_phil *philo, char *event);
#endif
