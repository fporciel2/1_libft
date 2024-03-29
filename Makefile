# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:20:25 by fporciel          #+#    #+#              #
#    Updated: 2023/11/19 13:12:38 by fporciel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# 
# This software is made available to anyone who wants to retrace the 
# author's learning path through the projects of school 42.
# Copyright (C) 2023  fporciel
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
# You can contact the author at: 
#- fporciel@student.42roma.it
#

.PHONY: all clean fclean re bonus
.DEFAULT_GOAL := $(NAME)
NAME := libft.a
SRCS := $(filter-out ft_lst%.c, $(wildcard ft_*.c) get_next_line.c)
BONUSSRCS := $(wildcard ft_lst*.c)
HEADERS := $(wildcard *.h)
OBJS := $(patsubst %.c,%.o,$(SRCS))
BONUSOBJS := $(patsubst %.c,%.o,$(BONUSSRCS))
CC := gcc
CFLAGS := -Wall -Wextra -Werror -O1 -g \
	-I$(shell pwd) -c

$(NAME): $(OBJS) $(HEADERS)
	@if [ ! -e $(NAME) ]; \
		then ar rcs $@ $^; fi
	@rm -f $(OBJS)

all: $(NAME)

$(OBJS): $(SRCS) $(HEADERS)
	@$(CC) $(CFLAGS) $^
	@rm -f *h.gch

$(BONUSOBJS): $(BONUSSRCS) $(HEADERS)
	@$(CC) $(CFLAGS) $^
	@rm -f *h.gch

bonus: $(BONUSOBJS)
	@if [ ! -e $(NAME) ]; \
		then make; fi
	@if ! make -q bonus; \
		then ar rcs $(NAME) $(BONUSOBJS); fi
	@make clean

clean:
	@rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

