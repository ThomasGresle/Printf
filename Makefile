SRCS		= srcs/parse.c srcs/print_letters.c srcs/print_numbers.c printf.c srcs/utils.c srcs/utils_libft.c srcs/ft_itoa.c srcs/ft_itoa_unsigned.c srcs/strjoin.c srcs/ft_itoa_base_p.c srcs/ft_print_char_part.c srcs/print_i.c srcs/cpynull.c

SRCSB		= 

OBJS		= $(SRCS:.c=.o)

OBJSB		= $(SRCSB:.c=.o)

NAME		= libftprintf.a

HEADER		= includes/ft_printf.h

CFLAGS		= -Wall -Wextra -Werror -I$(HEADER)

RM			= rm -f

CC			= cc

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

bonus:		$(OBJSB) $(OBJS) $(HEADER)
			ar rc $(NAME) $(OBJSB) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS) $(OBJSB)

fclean:		clean
			$(RM) $(NAME)

re :		fclean all

.PHONY:		re clean fclean
