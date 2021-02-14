##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC =	sources/window.c	\
		sources/init.c	\
		sources/event.c	\
		sources/draw_sprite.c	\
		sources/free_all.c

OBJ = $(SRC:.c=.o)

NAME = alexandra_in_the_world

SVFL = *~

CSFMLFLAGS = -l csfml-graphics -l csfml-audio -l csfml-window -l csfml-system
CFLAGS = -Wall -Wextra
DEMONFLAGS = -Werror
VALGRINDFLAGS = -g3

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS) $(CFLAGS)

clean:
	rm -rf $(SVFL)

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all

launch: re
	./$(NAME)

.PHONY: all clean fclean re launch
