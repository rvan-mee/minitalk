SRC =	ft_atoi.c			\
		ft_bzero.c			\
		ft_calloc.c			\
		ft_intlength.c		\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_isspace.c		\
		ft_itoa.c			\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_memset.c			\
		ft_putchar_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_putstr_fd.c		\
		ft_split.c			\
		ft_strchr.c			\
		ft_strdup.c			\
		ft_striteri.c		\
		ft_strjoin.c		\
		ft_strlcat.c		\
		ft_strlcpy.c		\
		ft_strlen.c			\
		ft_strmapi.c		\
		ft_strncmp.c		\
		ft_strnstr.c		\
		ft_strrchr.c		\
		ft_strtrim.c		\
		ft_substr.c			\
		ft_tolower.c		\
		ft_toupper.c		\
		exit_with_error.c

BNS = 	ft_lstadd_back_bonus.c	\
		ft_lstadd_front_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstdelone_bonus.c	\
		ft_lstiter_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstmap_bonus.c		\
		ft_lstnew_bonus.c		\
		ft_lstsize_bonus.c

NAME = libft.a

BNS_OBJ = $(BNS:_bonus.c=_bonus.o)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
## 		-fsanitize=address -g
CC = gcc

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(BNS_OBJ)
	@ar rcs $(NAME) $^

clean:
	@echo cleaning libft .o files 
	@rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	@echo cleaning libft .a files
	@rm -f libft.a

re: fclean all

.PHONY:	all bonus clean fclean re
