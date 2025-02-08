NAME = push_swap
BONUS = checker
HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
AR = ar -rcs

MAIN_MAN = main/main.c
SRC = parsing/ft_split.c parsing/list_new.c  parsing/ft_split2.c \
      parsing/sort_for_pos.c parsing/store_array_list.c parsing/main.c parsing/parcsing.c\
      operations/swap.c operations/rotate.c operations/reverse_rotate.c operations/push.c operations/extra_operation.c \
      algorthim2/main.c algorthim2/tiny_sort_simple.c algorthim2/helper_2.c \
	  algorthim2/big_sort.c algorthim2/helper.c algorthim2/tiny_sort_empty_stack.c\
      new_info/info.c

B_SRC = checkero/main.c gnl/get_next_line_utils.c gnl/get_next_line.c 

O_fILES = $(SRC:.c=.o)

O_B_FILES = $(B_SRC:.c=.o)

O_MAIN = $(MAIN_MAN:.c=.o)

all : $(NAME)

$(NAME) : $(O_fILES) $(O_MAIN)
	$(CC) $(O_fILES) $(O_MAIN) -o $(NAME)

bonus : $(NAME) $(O_fILES) $(O_B_FILES)
	$(CC) $(O_fILES) $(O_B_FILES) -o $(BONUS)

%.o:  %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_fILES) $(O_B_FILES) $(O_MAIN)

fclean: clean
	rm -rf $(NAME) $(BONUS) $(O_MAIN)

re: fclean all

.PHONY : all fclean clean re bonus