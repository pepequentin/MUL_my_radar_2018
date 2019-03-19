##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAME	=	my_radar

SRC	=	main.c\
		src/my_radar.c\
		src/display.c\
		src/other.c\
		src/colision.c\
		src/map_pos.c\
		src/tower.c\
		src/gestion_derreurs_radar.c\
		src/vraimain.c\

INCLUDE	=	-I ./include/

OBJ	=	$(SRC:.c=.o)

CSFML	=	-l csfml-system -l csfml-graphics -l csfml-window -lm

all: $(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CSFML)
	@rm -f $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
