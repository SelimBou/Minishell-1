##
## EPITECH PROJECT, 2023
## B-CPE-110-MAR-1-1-settingup-selim.bouasker
## File description:
## Makefile
##

SRC	=	main.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_printf.c	\
		my_strlen.c	\
		my_strcpy.c	\
		my_strdup.c	\
		strcmp.c	\
		extern_com.c	\
		intern_com.c	\

OBJ	=	$(SRC:.c=.o)

NAME	= mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
