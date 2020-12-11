/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:18:46 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/05 19:19:04 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int				ulen(unsigned int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void			ft_strrev(char *str)
{
	char			*t_begin;
	char			*t_end;
	unsigned int	len;
	char			temp;

	t_begin = str;
	t_end = str;
	len = ft_strlen(str);
	while (*t_end)
		t_end++;
	t_end--;
	while (t_begin - str < len / 2)
	{
		temp = *t_begin;
		*t_begin = *t_end;
		*t_end = temp;
		t_begin++;
		t_end--;
	}
}

char			*ft_utoa(unsigned int n)
{
	int		i;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)malloc(sizeof(char) * (ulen(n) + 1))))
		return (NULL);
	i = 0;
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
