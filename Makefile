
INC_DIR := inc

SRC_DIR := src
SRCS	:= strlen.s

OBJ_DIR := obj
OBJS	:= $(addprefix $(OBJ_DIR)/,$(SRCS:.s=.o))

NASM_FLAGS :=
NAME := libasm.a

.PHONY: all clean fclean re test bonus

all: $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	nasm -f macho64 -o $@ $<

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
