
NAME = fract_ol
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -g
CC = cc
ARCHIVE = ar -rcs

LIBMLX	= ./MLX42
LIBFT	= ./libft

LINKERS	= -ldl -lglfw -pthread -lm -lreadline
# GLFW_FLAGS	= `pkg-config --cflags glfw3 gl`
# GLFW_LIBS	= `pkg-config --libs glfw3 gl`

LIBS	= $(LIBMLX)/build/libmlx42.a
LIBS	+= $(LIBFT)/build/libft.a

INCLUDE_DIRS = -I $(LIBFT)/include -I $(LIBMLX)/include -I include

HEADER = include/fract_ol.h

FILES := \
	_error_handling.c \
	_output_state.c \
	_read_input.c \
	draw_image.c \
	draw_threads.c \
	main.c \
	occ_iter.c \
	occ_prev.c \
	shift.c \
	z_2.c \
	z_3.c \
	z_g.c \
	z_n.c \
	z_t.c \
	z_x.c \
	zoom.c \
	hooks/hooks.c \
	hooks/output_nonblocking.c

OBJECTS := $(FILES:.c=.o)

FILES := $(patsubst %.c, src/%.c, $(FILES))
OBJECTS := $(patsubst %.o, build/%.o, $(OBJECTS))

all: libmlx $(LIBFT) $(NAME)

bonus: all

libmlx: $(LIBMLX)
	git submodule init
	git submodule update
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	make -C $(LIBFT) all

$(NAME): build $(OBJECTS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) $(LINKERS) -o $(NAME)

fsanitize: build $(OBJECTS)
	$(CC) -fsanitize=address -g $(CFLAGS) $(OBJECTS) $(LINKERS) $(LIBS) -o $(NAME)

build:
	mkdir build
	mkdir build/hooks

build/%.o: src/%.c $(HEADER)
	$(CC) -c $(INCLUDE_DIRS) $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	make -C $(LIBFT) clean
	rm -rf $(LIBMLX)/build
	rm -rf $(OBJECTS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -rf $(LIBMLX)
	rm -rf $(NAME)
	rm -rf build

re: fclean all

re: fclean all

.PHONY: all bonus clean fclean re libmlx libft fsanitize