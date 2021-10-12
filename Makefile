# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ivork <ivork@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/21 18:14:25 by ivork         #+#    #+#                  #
#    Updated: 2021/10/12 17:31:38 by ivork         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
SRCS	=	src/push_swap.c\
			src/sort_operations.c\
			src/sort_short/sort_short.c\
			src/sort_long/sort_long.c\
			src/sort_long/sort_array.c\
			src/sort_long/rotate_b.c\
			src/helper.c\
			src/helper2.c\
			src/helper3.c
FLAGS	=	-Wall -Werror -Wextra -g
LIBFT	=	libft/libft.a
OBJS	=	$(SRCS:%.c=%.o)

all: $(NAME)
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
$(LIBFT):
	make -C libft
clean:
	make fclean -C libft
	rm -f *.o
fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
re: fclean all