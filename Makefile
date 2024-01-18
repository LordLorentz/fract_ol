
NAME = fract_ol
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -g
CC = cc
ARCHIVE = ar -rcs

LIBMLX	= ./MLX42
LIBFT	= ./libft

LINKERS	= -ldl -lglfw -pthread -lm

LIBS	= $(LIBMLX)/build/libmlx42.a
LIBS	+= $(LIBFT)/build/libft.a

INCLUDE_DIRS = -I $(LIBFT)/include -I $(LIBMLX)/include

FILES := \
	_output_state.c \
	_read_input.c \
	draw_image.c \
	error_handling.c \
	main.c \
	occ_iter.c \
	occ_prev.c \
	hooks.c \
	shift.c \
	z_2.c \
	z_3.c \
	z_n.c \
	z_t.c \
	z_x.c \
	zoom.c

OBJECTS := $(FILES:.c=.o)

FILES := $(patsubst %.c, src/%.c, $(FILES))
OBJECTS := $(patsubst %.o, build/%.o, $(OBJECTS))

all: libmlx $(LIBFT) $(NAME)

bonus: all

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	make -C $(LIBFT) all

$(NAME): build $(OBJECTS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LINKERS) $(LIBS) -o $(NAME)

fsanitize: build $(OBJECTS)
	$(CC) -fsanitize=address -g $(CFLAGS) $(OBJECTS) $(LINKERS) $(LIBS) -o $(NAME)

build:
	mkdir build

build/%.o: src/%.c
	$(CC) -c $(INCLUDE_DIRS) $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	make -C $(LIBFT) clean
	rm -rf $(LIBMLX)/build
	rm -rf $(OBJECTS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)
	rm -rf build

re: fclean all

re: fclean all

.PHONY: all bonus clean fclean re libmlx libft fsanitize