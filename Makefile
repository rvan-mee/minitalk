CLIENT_SRC = client_main.c	\

SERVER_SRC = server_main.c	\

SHARED_SRC =

CC = gcc

OBJDIR = objs/

CFLAGS = -Wall -Werror -Wextra
## -fsanitize=address -g
SERVER = server

CLIENT = client

CLIENT_OBJ = $(addprefix objs/, $(CLIENT_SRC:.c=.o) $(SHARED_OBJ))

SERVER_OBJ = $(addprefix objs/, $(SERVER_SRC:.c=.o) $(SHARED_OBJ))

SHARED_OBJ = $(SHARED_SRC:.c=.o)

$(SERVER): $(SERVER_OBJ)
	@make -C libft
	@$(CC) $(SERVER_OBJ) $(CFLAGS) libft/libft.a -o $(SERVER)

$(OBJDIR)%.o: src/server/%.c src/server/server.h
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT): $(CLIENT_OBJ)
	@make -C libft
	@$(CC) $(CLIENT_OBJ) $(CFLAGS) libft/libft.a -o $(CLIENT)

$(OBJDIR)%.o: src/client/%.c src/client/client.h
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)%.o: src/shared/%.c src/shared/shared.h
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo cleaning .o files
	@make -C libft clean
	@rm -f $(SHARED_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	@echo cleaning folders
	@rm -f libft/libft.a
	@rm -f $(CLIENT)
	@rm -f $(SERVER)

all: $(CLIENT) $(SERVER)

client: $(CLIENT)

server: $(SERVER)

re: fclean all

.PHONY: all clean fclean re client server
