##
## Makefile for add-apt-repository in /home/cadichon/Epitech/Debian_PPA
##
## Made by Cadichon
## Login   <leo.labruyere@epitech.eu>
##
## Started on  Tue Jun 13 16:45:37 2017 Cadichon
## Last update Tue Jun 13 16:54:49 2017 Cadichon
##

SRC	=	get_ppa_key.c

OBJ	=	$(SRC:.c=.o)

NAME	=	get_ppa_key

PROJECT =	add-apt-repository

CFLAGS	=	-W -Wall -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

dbg:		CFLAGS += -g
dbg:		re

install:
		cp $(NAME) /usr/bin/$(NAME)
		cp $(PROJECT) /usr/bin/$(NAME)

.PHONY:		all clean fclean dbg
