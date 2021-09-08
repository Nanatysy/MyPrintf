NAME = libftprintf.a
SRCC = ft_printf.c ft_str_processing.c ft_write_nb.c ft_write_c.c ft_hexadecimal_base.c ft_write_nb_extra.c
SRCO = $(SRCC:%.c=%.o)
FLAGS = -Wall -Werror -Wextra
LIBFT = libft.a

.PHONY: clean fclean re

all: $(LIBFT) $(NAME)

$(NAME): $(SRCO)
	cp libft/$(LIBFT) $(NAME)
	ar rcs $(NAME) $^

$(LIBFT):
	make -C ./libft

%.o: %.c libftprintf.h
	gcc $(FLAGS) -c $< 

clean:
	rm -f $(SRCO)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all