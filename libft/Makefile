
NAME	= 	libft.a

SRCS	=	${wildcard arr/*.c ascii/*.c math/*.c mem/*.c put/*.c str/*.c}

SRCS_B	= 	${wildcard lst/*.c}

HEADER	=	-I inc/
OBJ		=	${SRCS:%.c=%.o}
OBJ_B	=	${SRCS_B:%.c=%.o}

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror ${HEADER}

.PHONY	:	all clean fclean re bonus

all		:	${NAME}

${NAME}	:	${OBJ}
			@ar rcs ${NAME} $?
			@printf "File '${NAME}' is created !\n"

%.o 	: 	%.c ${HEADER}
			@${CC} ${CFALGS} -c $< -o $@

bonus	:
			@make OBJ="${OBJ_B}" all

clean	:
			@${RM} ${OBJ} ${OBJ_B}
			@printf "Files '*.o' are deleted !\n"

fclean	:	clean
			@${RM} ${NAME}
			@printf "File '${NAME}' is deleted !\n"

re		:	fclean all
