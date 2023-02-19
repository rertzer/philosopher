CC = gcc
FLAGS = -Wall -Wextra -Werror -pthread

NAME = philo_bonus

SRC_DIR = src/

OBJ_DIR = obj/

INC_DIR = includes/

SOURCES = clock.c \
		exit.c \
		init.c \
		main.c \
		parsing.c \
		philo.c \
		philo_life.c \
		run.c \
		semaphore.c \
		utils.c

OBJ = $(SOURCES:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -g -c $< -o $@ -I $(INC_DIR) 

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) -g -lrt -o $@ $(OBJS)

$(OBJ_DIR):
	mkdir  $(OBJ_DIR)

clean:
	rm -f $(OBJS)
	rm -fd $(OBJ_DIR)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re 
