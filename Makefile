
INC_DIR		:= inc
INC_FLAGS	:= $(addprefix -I ,$(INC_DIR))

LFLAGS		:= -L . -l asm

SRC_DIR		:= src
SRCS		:=	strlen.s	\
				strcpy.s	\
				strcmp.s

OBJ_DIR 	:= obj
OBJS		:= $(addprefix $(OBJ_DIR)/,$(SRCS:.s=.o))

NASM_FLAGS :=
NAME := libasm.a

.PHONY: all clean fclean re test bonus

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	nasm -f macho64 -o $@ $<

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

TEST_SRC_DIR	:= test
TEST_OBJ_DIR	:= $(OBJ_DIR)/test
TEST_SRCS		:= base.c
TEST_OBJS		:= $(addprefix $(TEST_OBJ_DIR)/,$(TEST_SRCS:.c=.o))
TEST_NAME		:= test_base

$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	gcc $(INC_FLAGS) -o $@ -c $<

test: $(NAME) $(TEST_OBJ_DIR) $(TEST_OBJS)
	gcc $(LFLAGS) -o $(TEST_NAME) $(TEST_OBJS)
	./$(TEST_NAME)
