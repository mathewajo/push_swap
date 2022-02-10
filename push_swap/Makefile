SRCS_SORTER =  push_swap.c \
          ./operation/short.c \
		  ./operation/bubble.c \
		  find_action.c \
		  ./operation/sort.c \
		  keep_p.c

SRCS_COMMON =   init.c \
                init2.c \
                init3.c \
				utills.c \
                ./operation/papb.c \
                ./operation/rarbrr.c \
                ./operation/rrarrbrrr.c \
                ./operation/sasbss.c \
                freeexit.c \

SRCS_CHECKER =	checkers/checker.c \
				checkers/get_next_line.c \
				checkers/utills.c \

OBJS_SORTER =	${SRCS_SORTER:.c=.o}
OBJS_COMMON =	${SRCS_COMMON:.c=.o}
OBJS_CHECKER =	${SRCS_CHECKER:.c=.o}

INCLUDE = 		./hfile

NAME =			push_swap
NAME_CHECKER =	checker

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -g
RM = 		rm -rf

all: 		${NAME}

bonus:		checker

.c.o:
			${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS_COMMON} ${OBJS_SORTER}
			${CC} ${CFLAGS} -I${INCLUDE} -o ${NAME} ${OBJS_COMMON} ${OBJS_SORTER}

${NAME_CHECKER}:	${OBJS_COMMON} ${OBJS_CHECKER}
					${CC} ${CFLAGS} -I${INCLUDE} -o ${NAME_CHECKER} ${OBJS_COMMON} ${OBJS_CHECKER}

clean:
			${RM} ${OBJS_COMMON} ${OBJS_CHECKER} ${OBJS_SORTER}

fclean:	clean
			${RM} ${NAME} ${NAME_CHECKER}

re:			fclean all

.PHONY:		bonus all clean fclean re