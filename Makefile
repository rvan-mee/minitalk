CLIENT_SRC = client.c	\

SERVER_SRC = server.c	\

CC = gcc

OBJDIR = objs/

CFLAGS = -Wall -Werror -Wextra
## -fsanitize=address -g
SERVER = server

CLIENT = client

CLIENT_OBJ = $(addprefix objs/, $(CLIENT_SRC:.c=.o))

SERVER_OBJ = $(addprefix objs/, $(SERVER_SRC:.c=.o))

$(SERVER): $(SERVER_OBJ)
	@make -C libft
	@$(CC) $(SERVER_OBJ) $(CFLAGS) libft/libft.a -o $(SERVER)

$(OBJDIR)%.o: src/server/%.c
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT): $(CLIENT_OBJ)
	@make -C libft
	@$(CC) $(CLIENT_OBJ) $(CFLAGS) libft/libft.a -o $(CLIENT)

$(OBJDIR)%.o: src/client/%.c
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo cleaning .o files
	@make -C libft clean
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	@echo cleaning folders
	@rm -f libft/libft.a
	@rm -f $(CLIENT)
	@rm -f $(SERVER)

all: $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re client server
