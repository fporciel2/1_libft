# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:20:25 by fporciel          #+#    #+#              #
#    Updated: 2023/03/04 10:10:11 by fporciel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus
.DEFAULT_GOAL := $(NAME)
NAME := libft.a
SRCS := $(filter-out ft_lst%.c, $(wildcard ft_*.c))
BONUSSRCS := $(wildcard ft_lst*.c)
HEADERS := $(wildcard *.h)
OBJS := $(patsubst %.c,%.o,$(SRCS))
BONUSOBJS := $(patsubst %.c,%.o,$(BONUSSRCS))
CC := gcc
CFLAGS := -Wall -Wextra -Werror -c

$(NAME): $(OBJS) $(HEADERS)
	ar rcs $@ $^

all: $(NAME)

$(OBJS): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $^

$(BONUSOBJS): $(BONUSSRCS) $(HEADERS)
	$(CC) $(CFLAGS) $^

bonus: $(NAME) $(BONUSOBJS)
	ar rcs $(NAME) $(BONUSOBJS)

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

