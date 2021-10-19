# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ivork <ivork@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/21 18:14:25 by ivork         #+#    #+#                  #
#    Updated: 2021/10/19 12:43:13 by ivork         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap checker
SRCS_PS	=	src/push_swap.c\
			src/sort_operations.c\
			src/sort_short/sort_short.c\
			src/sort_long/sort_long.c\
			src/sort_long/sort_array.c\
			src/sort_long/rotate_b.c\
			src/helper.c\
			src/helper1.c\
			src/helper2.c\
			src/helper3.c
SRCS_C	=	src/checker.c\
			src/sort_operations.c\
			src/helper.c\
			src/helper1.c\
			src/helper2.c\
			src/helper3.c
FLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
LIBFT	=	libft/libft.a
OBJS_PS	=	$(SRCS_PS:%.c=%.o)
OBJS_C	=	$(SRCS_C:%.c=%.o)

all: $(NAME)
$(word 1, $(NAME)): $(LIBFT) $(OBJS_PS)
	$(CC) $(FLAGS) $(OBJS_PS) $(LIBFT) -o $(word 1, $(NAME))
$(word 2, $(NAME)): $(LIBFT) $(OBJS_C)
	$(CC) $(FLAGS) $(OBJS_C) $(LIBFT) -o $(word 2, $(NAME))
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
$(LIBFT):
	make -C libft
clean:
	make fclean -C libft
	rm -f $(OBJS_PS) $(OBJS_C)
fclean: clean
	rm -f $(LIBFT)
	rm -f $(word 1, $(NAME))
	rm -f $(word 2, $(NAME))
re: fclean all