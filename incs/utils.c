/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:31:51 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/08 16:41:18 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				p;
	unsigned int	k;

	p = 1;
	i = 0;
	k = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ') && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p = -p;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = (k * 10) + str[i] - '0';
		i++;
	}
	k = k * p;
	return (k);
}
