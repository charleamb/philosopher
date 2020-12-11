/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:05:49 by chgilber          #+#    #+#             */
/*   Updated: 2020/12/05 19:21:56 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strndup(const char *s1, int len)
{
	int		i;
	char	*dup;
	char	*str;

	if (!s1)
		return (NULL);
	str = (char*)s1;
	if (!(dup = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;
	char	*str;

	if (!s1)
		return (NULL);
	str = (char*)s1;
	i = 0;
	while (str[i] != '\0')
		i++;
	if ((dup = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
