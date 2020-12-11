/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:49:33 by chgilber          #+#    #+#             */
/*   Updated: 2020/11/30 13:53:25 by chgilber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			*ft_memcpy_n(void *dst, void *src, unsigned int n)
{
	unsigned char *t_dst;
	unsigned char *t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	while (t_dst - (unsigned char*)dst < n)
	{
		*t_dst = *t_src;
		t_dst++;
		t_src++;
	}
	return (t_dst);
}

char			*ft_strjoindel(char *s1, char *s2, int param)
{
	char	*i_new;
	char	*new;

	if (!(new = (char*)malloc(sizeof(char)
	* ((ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	i_new = new;
	if (s1 || s2)
	{
		i_new = ft_memcpy_n(i_new, s1, ft_strlen(s1));
		i_new = ft_memcpy_n(i_new, s2, ft_strlen(s2));
	}
	*i_new = '\0';
	if (param == 1)
		free(s1);
	if (param == 2)
		free(s2);
	if (param == 3)
	{
		free(s1);
		free(s2);
	}
	return (new);
}
