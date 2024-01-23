
NAME = build/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
ARCHIVE = ar -rcs

INCLUDE_DIRS = -I ./include

FILES := \
	libc/ft_abs.c \
	libc/ft_atod.c \
	libc/ft_atoi.c \
	libc/ft_atol.c \
	libc/ft_bzero.c \
	libc/ft_calloc.c \
	libc/ft_dtoa.c \
	libc/ft_free_nptr_arr.c \
	libc/ft_free_ptr_arr.c \
	libc/ft_isalnum.c \
	libc/ft_isalpha.c \
	libc/ft_isascii.c \
	libc/ft_isdigit.c \
	libc/ft_isprint.c \
	libc/ft_isspace.c \
	libc/ft_itoa.c \
	libc/ft_long_digits.c \
	libc/ft_lstadd_back.c \
	libc/ft_lstadd_front.c \
	libc/ft_lstclear.c \
	libc/ft_lstdelone.c \
	libc/ft_lstiter.c \
	libc/ft_lstlast.c \
	libc/ft_lstmap.c \
	libc/ft_lstnew.c \
	libc/ft_lstsize.c \
	libc/ft_memchr.c \
	libc/ft_memcmp.c \
	libc/ft_memcpy.c \
	libc/ft_memmove.c \
	libc/ft_memset.c \
	libc/ft_putchar_fd.c \
	libc/ft_putendl_fd.c \
	libc/ft_putnbr_fd.c \
	libc/ft_putstr_fd.c \
	libc/ft_split.c \
	libc/ft_strchr.c \
	libc/ft_strcull.c \
	libc/ft_strdup.c \
	libc/ft_striteri.c \
	libc/ft_strjoin.c \
	libc/ft_strlcat.c \
	libc/ft_strlcpy.c \
	libc/ft_strlen.c \
	libc/ft_strlower.c \
	libc/ft_strmapi.c \
	libc/ft_strncmp.c \
	libc/ft_strnstr.c \
	libc/ft_strrchr.c \
	libc/ft_strtrim.c \
	libc/ft_substr.c \
	libc/ft_sz_digits.c \
	libc/ft_sztoa_base.c \
	libc/ft_tolower.c \
	libc/ft_toupper.c \
	printf/converters_char.c \
	printf/converters_dec.c \
	printf/converters_hex.c \
	printf/count_args.c \
	printf/decode.c \
	printf/fill_num.c \
	printf/find_flags.c \
	printf/ft_arr_cat.c \
	printf/ft_fprintf.c \
	printf/ft_printf.c \
	printf/ft_vsprintf.c \
	printf/get_next_arg.c \
	printf/justify_string.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
	

OBJECTS := $(FILES:.c=.o)

FILES := $(patsubst %.c, src/%.c, $(FILES))
OBJECTS := $(patsubst %.o, build/%.o, $(OBJECTS))

all: $(NAME)

$(NAME): build $(OBJECTS)
	$(ARCHIVE) $(NAME) $(OBJECTS)

build:
	mkdir build
	mkdir build/libc
	mkdir build/printf
	mkdir build/get_next_line

build/%.o: src/%.c
	$(CC) -c $(INCLUDE_DIRS) $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf build

re: fclean all

.PHONY: all clean fclean re