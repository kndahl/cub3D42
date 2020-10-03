# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdahl <kdahl@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 21:26:08 by kdahl             #+#    #+#              #
#    Updated: 2020/10/03 19:49:15 by kdahl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./libft.h

FUNCTIONS = ft_split.c ft_strmapi.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_itoa.c ft_putchar_fd.c ft_strnstr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_strrchr.c ft_strdup.c ft_strchr.c ft_memmove.c ft_memcmp.c ft_memchr.c ft_memccpy.c ft_isprint.c ft_isascii.c ft_isdigit.c ft_isalpha.c ft_memset.c ft_bzero.c ft_memcpy.c ft_tolower.c ft_toupper.c ft_atoi.c ft_calloc.c ft_isalnum.c

FUNCTIONS_BONUS = ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstclear.c ft_lstdelone.c ft_lstlast.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c

CC = gcc

OBJECTS = ${FUNCTIONS:.c=.o}

B_OBJECTS = ${FUNCTIONS_BONUS:.c=.o}

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $< -o ${<:.c=.o} -I $(HEADER)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus: $(B_OBJECTS)
	ar rc $(NAME) $(B_OBJECTS)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
