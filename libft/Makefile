# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmilagro <cmilagro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 19:24:54 by cmilagro          #+#    #+#              #
#    Updated: 2022/05/23 05:57:14 by cmilagro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_calloc.c ft_bzero.c\
	   ft_isalnum.c ft_isalpha.c ft_isascii.c\
	   ft_isdigit.c ft_isprint.c ft_memchr.c\
	   ft_memcmp.c ft_memcpy.c ft_memmove.c\
	   ft_memset.c ft_strchr.c ft_strdup.c\
	   ft_strlcat.c ft_strlcpy.c ft_strlen.c\
	   ft_strncmp.c ft_strnstr.c ft_strrchr.c\
	   ft_tolower.c ft_toupper.c ft_substr.c\
	   ft_strjoin.c ft_strtrim.c ft_itoa.c\
	   ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	   ft_split.c ft_isspace.c ft_strchrs.c ft_memalloc.c\
	   ft_strdel.c get_next_line.c ft_wdcounter.c

HEADER = libft.h
HEADER2 = get_next_line.h
OBJ    = $(patsubst %.c, %.o, $(SRCS))
BONUS  = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
		 ft_lstdelone.c ft_lstiter.c ft_lstlast.c\
		 ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJ = $(BONUS:.c=.o)

CC     = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -I$(HEADER) -I$(HEADER2)

.PHONY : all clean fclean re bonus

NAME = libft.a

all    : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	@$(RM) $(NAME)

re : all clean

bonus : $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
