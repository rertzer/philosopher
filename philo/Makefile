CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = philo

BONUS_NAME = philo_bonus

SRC_DIR = src/

MD_OBJ_DIR = obj_md/
BO_OBJ_DIR = obj_bo/

BONUS_DIR = philo_bonus/

INC_DIR = includes/

SOURCES = 

BONUS_SOURCES = 

BONUS_SRC_DIR = $(addprefix $(SRC_DIR), $(BONUS_DIR))

OBJ = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SOURCES:.c=.o)

OBJS = $(addprefix $(MD_OBJ_DIR), $(OBJ))
BONUS_OBJS = $(addprefix $(BO_OBJ_DIR), $(BONUS_OBJ))

all: $(NAME) $(BONUS_NAME)

bonus: $(BONUS_NAME)

$(MD_OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) 

$(BO_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) 

$(NAME): $(MD_OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) -o  $@ $(OBJS)

$(BONUS_NAME): $(BO_OBJ_DIR) $(BONUS_OBJS)
	$(CC) $(FLAGS) -o $@  $(BONUS_OBJS)

$(MD_OBJ_DIR):
	mkdir  $(MD_OBJ_DIR)

$(BO_OBJ_DIR):
	mkdir $(BO_OBJ_DIR)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -fd $(MD_OBJ_DIR)
	rm -fd $(BO_OBJ_DIR)

fclean: clean 
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re 
