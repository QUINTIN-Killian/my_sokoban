##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile to compile files with the lib.
## Makefile
##

SRC	=	$(wildcard *.c)

BIN_NAME	=	my_sokoban

FLAGS	=	-lncurses -g3 -W -Wall

all:	compile_lib compile

compile_lib:
	make re -C lib/my

compile:	$(OBJ)
	gcc $(SRC) -L. -lmy $(FLAGS) -o $(BIN_NAME)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean:	clean
	rm -f $(BIN_NAME)
	make fclean -C lib/my

re:	fclean all
