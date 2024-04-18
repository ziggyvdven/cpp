# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 12:46:32 by zvan-de-          #+#    #+#              #
#    Updated: 2024/04/17 21:09:08 by zvan-de-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


RT	= \033[0m
G	= \033[0;32m
B	= \033[0;34m
R 	= \033[0;31m

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Program name
NAME 			= template
# Compiler and flags
CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98

# others
RM				= rm -f
MAKE			= make

# Objects 
OBJS_PATH		= objs/
OBJS			= $(patsubst $(SRCS_PATH)%.cpp, $(OBJS_PATH)%.o, $(SRCS_FILES))

# Sources
SRCS_PATH		= srcs/
SRCS			= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

# Includes
HEADERS			= -I ./includes

# library and source files
SRCS_FILES		= $(wildcard $(SRCS_PATH)*.cpp)

# Progress bar variables
TOTAL 			= $(words $(SRCS_FILES))
CURR  			= 0
PERCENT 		= 0


define update_progress
    $(eval CURR=$(shell echo $$(($(CURR) + 1))))
    $(if $(TOTAL), \
        $(eval PERCENT=$(shell echo $$(($(CURR) * 100 / $(TOTAL))))) \
    )
    @printf "\r\\033[K$(B)$(NAME): $(RT) $(PERCENT)%% ["
    @for i in `seq 1 $(PERCENT)`; do \
        printf "$(G)=$(RT)"; \
    done
	@for i in `seq $(PERCENT) 100`; do \
        printf " "; \
    done
    @printf "]"
endef

define print_header
    @echo "$$HEADER"
endef

					
#------------------------------------------------------------------------------#
#                                 RULES                                        #
#------------------------------------------------------------------------------#

all: $(HEAD) $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	@$(CC)  $(CFLAGS) -o $@ $(OBJS) $(HEADERS)
	@echo "$(G)\n -- $(NAME) made ☎️ --$(RT)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< 
	$(call update_progress)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

clean:
	@rm -rf $(OBJS) $(OBJS_PATH)
	@echo "$(R)Files succesfully cleaned 🗑$(RT)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:		all, clean, fclean, re

# VALGRIND #

# val: $(NAME)
# 	valgrind --leak-check=full \
# 	--show-leak-kinds=all \
# 	--show-reachable=yes \
# 	--track-origins=yes -s \