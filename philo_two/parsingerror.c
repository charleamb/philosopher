/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingerror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:03:59 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/08 19:16:16 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		parsing_nb_philo(int nb)
{
	if (nb <= 1)
	{
		write(1, "Error : ", 8);
		write(1, "number of philosophers must be greater than 1.\n", 47);
		return (1);
	}
	if (nb > 200)
	{
		write(1, "Warning : ", 10);
		write(1, "very large number of philosophers, ", 35);
		write(1, "risk of slowing down or crashing.\n", 35);
	}
	return (0);
}

int		parsing_time_to(int time_to, char *s)
{
	if (time_to <= 0)
	{
		write(1, "Error : ", 8);
		write(1, s, ft_strlen(s));
		write(1, " can't be less than 1.\n", 23);
		return (1);
	}
	else if (time_to > 0 && time_to < 60)
	{
		write(1, "Warning : ", 10);
		write(1, s, ft_strlen(s));
		write(1, " less 60ms delay could be not enough for good result.\n", 54);
	}
	return (0);
}

int		parsing_number_of_meals(int nb_meals)
{
	if (nb_meals <= 0)
	{
		write(1, "Error : ", 8);
		write(1, "number_of_time_each_philosophers_must_eat ", 42);
		write(1, "can't be less than 1\n", 21);
		return (1);
	}
	return (0);
}

int		parsing_manager(t_all *all)
{
	if (parsing_nb_philo(all->nop))
		return (1);
	if (parsing_time_to(all->ttd, "time_to_die"))
		return (1);
	if (parsing_time_to(all->tte, "time_to_eat"))
		return (1);
	if (parsing_time_to(all->tts, "time_to_sleep"))
		return (1);
	if (all->meals == 1)
		if (parsing_number_of_meals(all->noe))
			return (1);
	return (0);
}
