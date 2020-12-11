# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 11:50:11 by chgilber          #+#    #+#              #
#    Updated: 2020/12/10 14:59:49 by chgilber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_2

SRCS =	../incs/ft_strdup.c\
		../incs/ft_strlen.c\
		../incs/get_le_temps.c\
		../incs/messagerror.c\
		../incs/parsing.c\
		../incs/utils.c\
		../incs/utoa.c\
		../incs/ft_lenbr.c\
		../incs/ft_strjoindel.c\
		display.c\
		init_philo.c\
		main.c\
		monitor.c\
		parsingerror.c\
		philo_do.c\
		reaper.c\
	

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

# Text format
_DEF = $'\033[0m
_END = $'\033[0m
_GRAS = $'\033[1m
_SOUL = $'\033[4m
_CLIG = $'\033[5m
_SURL = $'\033[7m

# Colors
_BLACK = $'\033[30m
_RED = $'\033[31m
_GREEN = $'\033[32m
_YELLOW = $'\033[33m
_BLUE = $'\033[34m
_PURPLE = $'\033[35m
_CYAN = $'\033[36m
_GREY = $'\033[37m

# Background
_IBLACK = $'\033[40m
_IRED = $'\033[41m
_IGREEN = $'\033[42m
_IYELLOW = $'\033[43m
_IBLUE = $'\033[44m
_IPURPLE = $'\033[45m
_ICYAN = $'\033[46m
_IGREY = $'\033[47m

OBJS = $(SRCS:.c=.o)
OBJS_LIB = $(SRCSLIB:.c=.o)

all : $(NAME)

-include $(DPDCS)

$(NAME) : $(OBJS)
	@echo "$(_END)$(_GREEN) [OK]\t"
	@gcc $(CFLAGS) -o $@ $(OBJS) -pthread
	@echo "$(_END)$(_GREEN)[Philo_2]"

%.o : %.c
	@echo "$(_END)$(_GREEN) [OK]\t"
	@$(CC) $(CFLAGS) -o ${<:.c=.o} -c $<

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all re fclean clean bonus
