/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:27:19 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/05 19:30:04 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		display_allmeals(t_all *all)
{
	char			*time;
	char			*dot;
	unsigned int	current_time;

	current_time = l_heure(all->start_usec, all->start_sec);
	dot = ".......";
	time = ft_utoa(current_time);
	write(1, dot, ft_strlen(dot) - len_nb(current_time));
	write(1, time, ft_strlen(time));
	free(time);
	write(1, "   ", 3);
	write(1, "all the meals ate\n\n", 19);
}

void		display_manager(t_all *s, t_phil *philo, char *event)
{
	char			*time;
	char			*id;
	char			*dot;
	char			*str;
	unsigned int	current_time;

	str = NULL;
	current_time = l_heure(s->start_usec, s->start_sec);
	dot = ".......";
	time = ft_utoa(current_time);
	id = ft_utoa(philo->num);
	str = ft_strndup(dot, ft_strlen(dot) - len_nb(current_time));
	str = ft_strjoindel(str, time, 3);
	str = ft_strjoindel(str, " ", 1);
	str = ft_strjoindel(str, id, 3);
	str = ft_strjoindel(str, " ", 1);
	str = ft_strjoindel(str, event, 1);
	str = ft_strjoindel(str, "\n", 1);
	write(1, str, ft_strlen(str));
	free(str);
}
