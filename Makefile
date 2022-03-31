NAME		:= minishell
SRC			:=   handlers.c  strings.c minishell.c parse.c quotes.c ./strings/ft_strdup_v2.c multipipes.c  here_doc_check.c  split_spaces.c _echo.c _env.c
SRCB		:=  
OBJ			:= $(patsubst %.c, %.o, $(SRC)) 
OBJB		:= $(patsubst %.c, %.o, $(SRCB)) 
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror 
LIBFTDIR	:= ./libft/
LIBFT		:= ./libft/libft.a
.PHONY: all clean fclean re bonus

all: $(NAME)
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) -lreadline $(OBJ) $(LIBFT) -o $(NAME) 
%.o: %.c
	$(CC) $(FLAGS) -c $<  -o $@

$(LIBFT):
	@make -C $(LIBFTDIR)

clean:
	@make -C $(LIBFTDIR) fclean
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJB) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJB) -o $(NAME)

t: $(NAME)
	./$(NAME)