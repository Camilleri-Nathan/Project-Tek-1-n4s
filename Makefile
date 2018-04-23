##
## EPITECH PROJECT, 2018
## n4s
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -f

OBJS		=	$(addprefix $(SRCDIR), $(SRCS:.c=.o))

SRCDIR		=	src/

MAKE		=	make -C

CFLAGS		=	-W -Wall -Wextra
CFLAGS		+=	-I./include/

NAME		=	ia

SRCS		=	tools/my_put_nbr.c		\
			tools/get_next_line.c		\
			tools/my_int_to_str.c		\
			tools/my_realloc.c		\
			tools/my_revstr.c		\
			tools/my_str_to_word_array.c	\
			parcing_captor.c	\
			commands_info_car.c		\
			commands_info_time_and_cycle.c	\
			commands_move_car.c		\
			commands_simulations.c		\
			ia.c				\
			main.c

DEBUG		=	no

ifeq ($(DEBUG),yes)
CFLAGS		+= -g
else
CFLAGS		+= -Werror
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
