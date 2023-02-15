NAME = push_swap
NAME_BONUS = checker

FLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC = mendatory/ft_split.c mendatory/libft_helpers.c mendatory/main.c mendatory/push_swap_utils.c mendatory/rules.c mendatory/sort_h.c mendatory/sort.c mendatory/rules2.c mendatory/rules3.c
SRC_B = bonus/ft_split.c bonus/libft_helpers.c bonus/main.c bonus/push_swap_utils.c bonus/rules.c  bonus/checker.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c bonus/rules2.c bonus/rules3.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all:	$(NAME) 
bonus:	$(NAME_BONUS)


$(NAME):	$(OBJ)
	cc $(FLAGS) $(OBJ)  -o $(NAME)
$(NAME_BONUS):	$(OBJ_B)
	cc $(FLAGS) $(OBJ_B)  -o $(NAME_BONUS)

clean:	
	$(RM) $(OBJ) $(OBJ_B)

fclean:	clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus