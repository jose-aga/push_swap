# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-aga <jose-aga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 10:24:15 by jose-aga          #+#    #+#              #
#    Updated: 2023/03/13 11:39:18 by jose-aga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c \
		check_errors.c check_errors_aux.c \
		ft_move.c move.c mov_cost.c errors.c \
		pos_ops.c rev_rotate_movs.c \
		rotate_movs.c sort_method.c sort_movs.c \
		stacks_init.c stacks_moves.c ft_split.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

ifdef D
	CFLAGS += -g
endif

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

##########################
## Test rules for Linux ##
##########################

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

########################
## Test rules for Mac ##
########################

mtest2:				$(NAME)
					$(eval ARG = $(shell ruby -e "puts (-1..0).to_a.shuffle.join(' ')"))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

mtest3:				$(NAME)
					$(eval ARG = $(shell ruby -e "puts (-1..1).to_a.shuffle.join(' ')"))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

mtest5:				$(NAME)
					$(eval ARG = $(shell ruby -e "puts (-2..2).to_a.shuffle.join(' ')"))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

mtest100:			$(NAME)
					$(eval ARG = $(shell ruby -e "puts (-50..49).to_a.shuffle.join(' ')"))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

mtest500:			$(NAME)	
					$(eval ARG = $(shell ruby -e "puts (-250..249).to_a.shuffle.join(' ')"))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l				

mtest1000:			$(NAME)	
					$(eval ARG = $(shell ruby -e "puts (-500..499).to_a.shuffle.join(' ')"))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
		mtest2 mtest3 mtest5 mtest100 mtest500 mtest1000