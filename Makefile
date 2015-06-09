##
## Makefile for  in /home/mart_4/rendu/TestPiscine/rwold
## 
## Made by Thomas Martins
## Login   <mart_4@epitech.eu>
## 
## Started on  Sat Dec 20 09:40:23 2014 Thomas Martins
## Last update Sat Dec 20 09:40:23 2014 Thomas Martins
##

SRC	= control.c \
	function_all.c \
	main.c \
	wall.c \
	hook.c \
	my_map.c

NAME	= wolf3d

OBJ	= $(SRC:.c=.o)

RM	= rm -f

all:	$(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm

clean:
	$(RM) $(OBJ)


fclean:		clean
	$(RM) $(NAME)

re: fclean all
