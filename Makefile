NAME		=	so_long

LIB_PATH	=	libft/

LIB			=	${LIB_PATH}libft.a

SRCS		=	${wildcard *.c}

SRCS_BONUS	=	${wildcard bonus/*.c}

MLX_PATH	=	minilibx_opengl_20191021/

MLX			=	${MLX_PATH}libmlx.a

MLXFLAGS	=	-L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit

HEADER		=	-I include/
OBJS		=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra ${HEADER}

ifdef WITH_BONUS
	OBJS_FILES = $(OBJS_BONUS)
else
	OBJS_FILES = $(OBJS)
endif

.PHONY		:	all subsystem clean fclean re bonus

all			:	subsystem_mlx subsystem ${NAME}

bonus		:
				make WITH_BONUS=1 all

subsystem_mlx:	
				@make -C ${MLX_PATH} all
				@printf "\033[0;33m💬 File '${MLX}' is created ! 🍀\033[0m\n"

subsystem	:	
				@make -C ${LIB_PATH} all
				@printf "\033[0;33m💬 File '${LIB}' is created ! 🍀\033[0m\n"

${NAME}		:	${OBJS_FILES}
				${CC} ${CFLAGS} ${OBJS_FILES} ${LIB} ${MLXFLAGS} ${MLX} -o ${NAME}
				@printf "\033[0;32m💬 File 'so_long' is created ! 🍀\033[0m\n"

clean		:	
				@make -C ${MLX_PATH} clean
				@make -C ${LIB_PATH} clean
				@rm -rf ${OBJS} ${OBJS_BONUS}
				@printf "\033[0;34m💬 Files '${MLX}' and '${OBJS_FILES}' are deleted ! 👻\033[0m\n"

fclean		:	clean
				@make -C ${LIB_PATH} fclean
				@rm -rf ${NAME}
				@printf "\033[0;31m💬 Files '${LIB}' and '${NAME}' are deleted ! 👻\033[0m\n"

re			:	fclean all

