# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 21:50:40 by rkandiyi          #+#    #+#              #
#    Updated: 2023/03/11 16:14:58 by rkandiyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	so_long.c \
		check.c \
		read_map.c \
		move_player.c \
		msg.c \
		render.c \
		utils/check_utils.c \
		utils/gnl_utils.c \
		free.c \
		ft_printf.c \
		valid_path.c


OBJ = $(SRCS:.c=.o)

# CC = cc

RM				= rm -fr
CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C mlx
	$(CC) $(OBJ) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


		
clean:
	(cd mlx && make clean)
	$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:			all clean fclean re bonus