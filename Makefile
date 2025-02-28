# Nom de l'exécutable
NAME = push_swap

# Liste des fichiers sources
SRC = 	bool.c \
		cost.c \
		find.c \
		lst.c \
		main.c \
		parsing_1.c \
		parsing_2.c \
		push.c \
		rev_rot.c \
		rot.c \
		sort.c \
		sort_utils.c \
		split.c \
		swap.c \
		calloc.c \

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SANITIZE = -fsanitize=address -g

# Commandes
RM = rm -f

# Règle par défaut
all: $(NAME)

# Création de l'exécutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

flags: $(OBJ)
	$(CC) $(CFLAGS) $(SANITIZE) $(OBJ) -o $(NAME)

# Compilation des fichiers objets
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJ)

# Nettoyage complet (objets + exécutable)
fclean: clean
	$(RM) $(NAME)

# Règle pour la recompilation complète
re: fclean all

.PHONY: all clean fclean re