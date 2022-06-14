# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 00:55:30 by rvrignon          #+#    #+#              #
#    Updated: 2022/06/14 19:11:10 by rvrignon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  	ft_fdf/main.c \
		ft_fdf/render/background.c \
		ft_fdf/render/rectangle.c \
		ft_fdf/render/utils.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -g -I/usr/include -Imlx_Linux -O3 -c $< -o $@

NAME	=	ft_fdf/fdf.a

PROG	=	fdf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) all -C libft
			cp libft/libft.a mlx_Linux/libmlx.a
			$(MAKE) all -C mlx_Linux
			$(CC) $(OBJ) -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -o $(PROG)
			@echo "\033[1;32m"
			@echo "\033[4;36mFDF is now ready to be used!\033[0m"
			@echo "\033[4;32mGOOD WORK\033[0m"

%.o: %.c
	$(CC) $(CFLAGS)

clean:		
			$(MAKE) fclean -C ./libft
			$(MAKE) clean -C ./mlx_Linux
			$(RM) $(NAME) $(OBJ)
			@echo "\033[1;32m"
			@echo "\033[4;36mFDF is now clean!\033[0m"
			@echo "\033[4;32mGOOD WORK\033[0m"

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(PROG)
			@echo "\033[1;32m"
			@echo "\033[4;36mFDF is now clean!\033[0m"
			@echo "\033[4;32mGOOD WORK\033[0m"

re:			fclean $(NAME) $(NAME_CHECKER)

.PHONY:		all clean fclean re