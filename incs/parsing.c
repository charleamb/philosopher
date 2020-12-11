/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:24:42 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/08 16:49:49 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		print_error_not_enought_arg(void)
{
	write(1, "Error : ", 8);
	write(1, " the program need 5 or 6 arguments.\n", 36);
	return (print_usage());
}

int		print_usage(void)
{
	write(1, "Usage : \n", 9);
	write(1, "\t./philo ", 9);
	write(1, "number_of_philosopher time_to_die time_to_eat time_to_sleep ",
	60);
	write(1, "[number_of_time_each_philosophers_must_eat]\n", 45);
	write(1, "\tDigit only\n", 12);
	return (0);
}

void	initdata(t_all *all)
{
	all->nop = 0;
	all->ttd = 0;
	all->tte = 0;
	all->tts = 0;
	all->noe = 0;
	all->meals = 0;
	all->sm1die = 0;
	all->mealfinish = 0;
	all->start_usec = startime(0);
	all->start_sec = startime(1);
}

int		datafilo(int ac, char **av, t_all *all)
{
	initdata(all);
	if (ac < 5 || (ac > 4 && (!ft_isdigit(av[1]) || !ft_isdigit(av[2]) ||
	!ft_isdigit(av[3]) || !ft_isdigit(av[4]))) || ac > 6)
		return (print_error_not_enought_arg());
	all->nop = ft_atoi(av[1]);
	all->ttd = ft_atoi(av[2]);
	all->tte = ft_atoi(av[3]);
	all->tts = ft_atoi(av[4]);
	if (ac == 6 && ft_isdigit(av[5]))
	{
		all->meals = 1;
		all->noe = ft_atoi(av[5]);
	}
	else if (ac == 6 && !ft_isdigit(av[5]))
		return (print_error_not_enought_arg());
	if (parsing_manager(all))
		return (0);
	return (1);
}
