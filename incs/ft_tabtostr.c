/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:01:00 by chgilber          #+#    #+#             */
/*   Updated: 2020/11/30 14:07:14 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char		*ft_strtabtostr(char **s)
{
	int		i;
	int		n;
	int		len;
	char	*str;

	len = 0;
	while (s[len])
		len++;
	len = len * 7;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	len = 0;
	while (s[i] != NULL)
	{
		n = 0;
		while (s[i][n])
			str[len++] = s[i][n++];
		i++;
	}
	str[len++] = '\0';
	return (str);
}
