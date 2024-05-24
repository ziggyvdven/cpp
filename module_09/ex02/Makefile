# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 12:46:32 by zvan-de-          #+#    #+#              #
#    Updated: 2024/05/24 16:36:47 by zvan-de-         ###   ########.fr        #
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
NAME 			= PmergeMe
NAME_EXPLAIN	= PmergeMe_explain

# Compiler and flags
CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98 -g

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
HEADERS			= -I ./includes/PmergeMe.hpp
HEADERS_EXPLAIN	= -I ./includes/PmergeMe_explain.hpp

# library and source files
SRCS_FILES		    = $(SRCS_PATH)main.cpp
SRCS_FILES_EXPLAIN	= $(SRCS_PATH)main_explain.cpp

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
	@$(RM) $(NAME) $(NAME_EXPLAIN)

re: fclean all

explain:
	@$(MAKE) "NAME=$(NAME_EXPLAIN)" "SRCS_FILES=$(SRCS_FILES_EXPLAIN)" "HEADER=$(HEADERS_EXPLAIN)"
	@./$(NAME_EXPLAIN) 4 2 5 1 7 6 3 9 8 

.PHONY:		all clean fclean re explain
