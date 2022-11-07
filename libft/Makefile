
SRCS = ft_atoi.c ft_bzero.c	ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c	ft_memcmp.c\
	 ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c\
	 ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
	 ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\
	 get_next_line.c get_next_line_utils.c ft_strcmp_bonus.c ft_numspases_bonus.c ft_free2arr_bonus.c

H = libft.h

OBJS = ${patsubst %.c,%.o,${SRCS}}

D_FILES = ${patsubst %.c,%.d,${SRCS} ${SRCS_B}} 

NAME = libft.a

CC = gcc

RM = @rm -f

FLAGS = -Wall -Werror -Wextra

OPTFLAGS = -O2

all:	${NAME}

${NAME}:	${OBJS}
		ar rcs ${NAME} $?
#		${RM} ${OBJS} ${D_FILES}

%.o : %.c
		${CC} ${FLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

clean:		
		-${RM} ${OBJS} ${D_FILES}

fclean:		clean
		-${RM} ${NAME}

re:		fclean all

bonus:

.PHONY:		all clean fclean re bonus
