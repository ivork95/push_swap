# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ivork <ivork@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/21 18:14:25 by ivork         #+#    #+#                  #
#    Updated: 2021/06/09 15:17:45 by ivork         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
SRCS	=	push_swap.c\
			sort_operations.c\
			sort_stack.c\
			sort_short.c\
			tree.c\
			helper.c
FLAGS	=	-Wall -Werror -Wextra
LIBFT	=	libft/libft.a
OBJS	= 	$(SRCS:%.c=%.o)

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