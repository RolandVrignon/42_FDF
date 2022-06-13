# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 00:55:30 by rvrignon          #+#    #+#              #
#    Updated: 2022/06/14 01:09:36 by rvrignon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  	ft_fdf/main.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

NAME	=	ft_fdf/fdf.a

PROG	=	fdf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) all -C libft
			cp libft/libft.a minilibx/libmlx.a
			$(MAKE) all -C minilibx
			cp minilibx/libmlx.a $(NAME)
			ar rcs $(NAME) $(OBJ)
			$(CC) $(CFLAGS) -o $(PROG) $(SRC) $(NAME)
			@echo "\033[1;32m"
			@echo "\033[4;36mFDF is now ready to be used!\033[0m"
			@echo "\033[4;32mGOOD WORK\033[0m"

clean:		
			$(MAKE) fclean -C ./libft
			$(MAKE) clean -C ./minilibx
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