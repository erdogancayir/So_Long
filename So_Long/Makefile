CC	= gcc
MINILIBX	= minilibx/libmlx.a
NAME 		= so_long	
FLAGS		= -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit
BNAME		= so_long_bonus
SRCS 		= src/conver_to_xpm.c src/ft_create_map.c src/ft_init_map.c src/ft_split_fs.c src/key_pressed.c src/so_long_checks.c src/so_long_utils.c src/so_long.c
OBJS 		= $(SRCS:.c=.o)
BSRCS		= bonus/bonus.c bonus/bonus_checks.c bonus/bonus_key_press.c bonus/bonus_utils.c bonus/conver_bonus.c bonus/create_map_bonus.c bonus/ft_animator.c bonus/ft_init_map_bonus.c bonus/ft_split_fs_bonus.c
BOBJS		= $(BSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(MINILIBX) $(OBJS)
	$(CC) $(LFLAGS) $(FLAGS) $(OBJS) -o $(NAME) ./printf/libftprintf.a ./libft/libft.a minilibx/libmlx.a
	
bonus : $(BNAME)

$(BNAME) : $(MINILIBX) $(BOBJS)
	$(CC) $(LFLAGS) $(FLAGS) $(BOBJS) -o $(BNAME) ./printf/libftprintf.a ./libft/libft.a minilibx/libmlx.a

$(MINILIBX):
	make -C minilibx
	@echo "\033[0;95mMINILIBX compile OLDU"

run: all
	./$(NAME) maps/map1.ber
re: fclean all
clean:
	rm -rf $(OBJS)
	rm -rf $(BOBJS)
norm:
	@norminette src/*.c
	@norminette bonus/*.c
	
fclean:
	rm -rf $(NAME)
	@make clean -C minilibx
	@make clean -C printf
.PHONY: clean run fclean re all
		