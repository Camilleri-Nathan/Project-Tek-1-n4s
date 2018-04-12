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

NAME		=	./resources/ai

SRCS		=	tools/my_putstr.c \
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
