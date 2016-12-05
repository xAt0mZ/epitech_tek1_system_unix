##cet include determine les regles de compilation pour la compatibilite 32b
include $(HOME)/compat/Makefile

##pour ajouter vos propres flags a la compilation faites "CFLAGS +=  'vos flags'"
##pour ajouter vos propres flags au linkage faites "LDFLAGS +=  'vos flags'"


CC	=	gcc
CFLAGS	+= 	-W -Wall
SRC	=	main.c
OBJ 	=	$(SRC:.c=.o)
NAME	=	six

all: $(NAME)

$(NAME) : $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
