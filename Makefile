##
## EPITECH PROJECT, 2018
## n4s
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

DIR_SRC	=	src

SRC	=	$(DIR_SRC)/main.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

CFLAGS	=	-I./include

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
