FILES   := coordination.c error_management.c draw_3D.c \
		   fdf.c get_color.c scale_center.c gnl/get_next_line.c \
		   gnl/get_next_line_utils.c

NAME	:= fdf
INC     := libft/
CFLAGS	:= -Wextra -Wall -Werror
LIBMLX	:= ./MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a
LIBRARY := libft.a
OFILES  := $(FILES:.c=.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBRARY):
	@make re -C $(INC)

$(NAME): $(LIBRARY) $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(LIBRARY) $(LIBS) -lglfw -o $(NAME) -fsanitize=address

clean:
	@rm -rf $(OFILES)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBRARY)

fclean: clean
	@rm -rf $(NAME)

re: clean all