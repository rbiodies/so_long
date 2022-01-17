NAME		=	so_long

LIB_PATH	=	libft/

LIB			=	${LIB_PATH}libft.a

SRCS		=	main.c so_long.c parsing_map.c \
				get_next_line.c valid_map.c \
				paint_map.c key_event.c

SRCS_BONUS	=	bonus/main_bonus.c bonus/so_long_bonus.c bonus/parsing_map_bonus.c \
				bonus/get_next_line_bonus.c bonus/valid_map_bonus.c bonus/enemy_bonus.c \
				bonus/paint_map_bonus.c bonus/key_event_bonus.c bonus/player_loop_bonus.c \

MLX_PATH	=	minilibx_opengl_20191021/

MLX			=	${MLX_PATH}libmlx.a

MLXFLAGS	=	-lmlx -framework OpenGL -framework Appkit

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

all			:	subsystem ${NAME}

bonus		:
				make WITH_BONUS=1 all

subsystem	:	
				make -C ${LIB_PATH} all
				@printf "\033[0;32m💬 Libft make complete !\033[0m\n"

${NAME}		:	${OBJS_FILES}
				${CC} ${CFLAGS} ${OBJS_FILES} ${LIB} ${MLXFLAGS} ${MLX} -o ${NAME}
				@printf "\033[0;33m💬 Create file 'so_long' !\033[0m\n"

clean		:	
				make -C ${LIB_PATH} clean
				rm -f ${OBJS} ${OBJS_BONUS}
				@printf "\033[0;34m👻 Files *.o clean ! 👻\033[0m\n"

fclean		:			
				make -C ${LIB_PATH} fclean
				rm -f ${OBJS} ${OBJS_BONUS}
				rm -f ${NAME}
				@printf "\033[0;32m🍀 All clean ! 🍀\033[0m\n"

re			:	fclean all

