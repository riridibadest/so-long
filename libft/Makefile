CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a
SRC = ft_strdup.c ft_calloc.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
ft_isprint.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_tolower.c \
ft_toupper.c ft_isalnum.c ft_isascii.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strchr.c ft_putstr_fd.c \
ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_putnbr_fd.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putendl_fd.c \
ft_itoa.c ft_striteri.c ft_split.c ft_strmapi.c ft_printf/ft_printf.c \
ft_printf/check_speci.c ft_printf/speci_c.c ft_printf/speci_ind.c \
ft_printf/speci_p.c ft_printf/speci_s.c ft_printf/speci_u.c ft_printf/speci_x.c \
ft_printf/speci_xup.c

BONUS_SRC = ft_lstnew_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstmap_bonus.c\

OBJS = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

HDRS = libft.h
# Target
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# Ar create lib $@ target name $^ all obj files
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	

#clean object files
clean:
	rm -f $(OBJS) $(BONUS_OBJ)

# Clean Object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Rule for the bonus functions
bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)
