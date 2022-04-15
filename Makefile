SERVER_TARGET = server
CLIENT_TARGET = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

CFLAGS = -Wall -Werror -Wextra
CC = gcc

OBJDIR = objs
CLIENT_OBJ = $(addprefix objs/, $(CLIENT_SRC:%.c=%.o))
SERVER_OBJ = $(addprefix objs/, $(SERVER_SRC:%.c=%.o))

all: $(CLIENT_TARGET) $(SERVER_TARGET)

$(SERVER_TARGET): $(SERVER_OBJ)
	@make -C libft
	@echo compiling server...
	@$(CC) $(SERVER_OBJ) $(CFLAGS) libft/libft.a -o $(SERVER_TARGET)

$(CLIENT_TARGET): $(CLIENT_OBJ)
	@make -C libft
	@echo compiling client...
	@$(CC) $(CLIENT_OBJ) $(CFLAGS) libft/libft.a -o $(CLIENT_TARGET)

$(OBJDIR)/%.o: src/server/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: src/client/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p objs

bonus: all

clean:
	@echo cleaning .o files
	@make -C libft clean
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	@echo cleaning folders
	@rm -f libft/libft.a
	@rm -f $(CLIENT_TARGET) $(SERVER_TARGET)
	@rm -rf objs

re: fclean all

.PHONY: all clean fclean re
