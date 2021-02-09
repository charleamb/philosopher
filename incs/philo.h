/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chgilber <charleambg@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:06:32 by chgilber          #+#    #+#             */
/*   Updated: 2021/02/09 14:16:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <signal.h>
# include <sys/time.h>
# include <stdbool.h>

# define MILLE 1000
# define EVENT_FORK		"has taken a fork"
# define EVENT_EAT		"is eating"
# define EVENT_SLEEP	"is sleeping"
# define EVENT_THINK	"is thinking"
# define EVENT_DEAD		"is dead"

typedef	struct	s_all
{
	unsigned int	start_usec;
	unsigned int	start_sec;
	unsigned int	nop;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	unsigned int	noe;
	bool			sm1die;
	bool			meals;
	unsigned int	mealfinish;
}				t_all;

int				ft_isdigit(char *str);
int				ft_atoi(char *str);
int				error(int i);
int				print_error_not_enought_arg(void);
int				print_usage(void);
int				datafilo(int ac, char **av, t_all *all);
int				parsing_manager(t_all *all);
unsigned int	l_heure(unsigned int start_usec, unsigned int start_sec);
unsigned int	startime(int time);
void			*reaper(void *all);
int				len_nb(unsigned int nb);
void			ft_strrev(char *str);
int				ulen(unsigned int n);
char			*ft_utoa(unsigned int n);
int				ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, int len);
void			*ft_memcpy_n(void *dst, void *src, unsigned int n);
char			*ft_strjoindel(char *s1, char *s2, int param);
char			*ft_strtabtostr(char **s);
#endif
