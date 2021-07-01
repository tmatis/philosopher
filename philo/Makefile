# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 16:38:19 by tmatis            #+#    #+#              #
#    Updated: 2021/07/01 16:41:04 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################


NAME	= philo
CC 		= clang
CFLAGS	= -Wall -Werror -Wextra -g
LIBFT	= libft/libft.a
AUTHOR	= tmatis
DATE	= 25/03/2021

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS_PATH	= src

SRCS		= utils/put.c utils/atoi.c utils/time.c parser.c \
			  manager/manager_setup.c manager/manager_func.c philosopher/philo.c \
			  philosopher/philo_fork.c philosopher/philo_action.c

MAIN		= main.c

################################################################################
#                                     TESTS's SRCS                             #
################################################################################

TEST_NAME		= test

SRCS_TESTS_PATH	= tests

SRCS_TESTS		= main.c assert/assert_utils.c assert/assert.c assert/redirect_out.c \
				  test_time.c utils.c test_atoi.c test_parser.c assert/assert_stdout.c \
				  test_manager.c test_philo.c

################################################################################
#                                 Makefile logic                               #
################################################################################


OBJ_MAIN	= $(addprefix objs/, ${MAIN:.c=.o})
OBJS		= $(addprefix objs/, ${SRCS:.c=.o})
OBJS_TESTS	= $(addprefix objs_tests/, ${SRCS_TESTS:.c=.o})

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[KO]"
WARN_STRING  = "[WARN]"
COM_STRING   = "Compiling"

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
else  \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

all:	header $(NAME)

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "        ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___|"
	@echo
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
	@echo

$(NAME): 	${OBJS} ${OBJ_MAIN}
			@$(call run_and_test,$(CC) $(CFLAGS) -o $@ ${OBJS} ${OBJ_MAIN} -lpthread)

$(TEST_NAME):	header $(OBJS_TESTS) $(OBJS)
			@$(call run_and_test,$(CC) $(CFLAGS) -o $@ $(OBJS_TESTS) $(OBJS) -lpthread)

objs/%.o: 	$(SRCS_PATH)/%.c
			@mkdir -p $(dir $@)
			@$(call run_and_test,$(CC) $(CFLAGS) -c $< -o $@)

objs_tests/%.o: $(SRCS_TESTS_PATH)/%.c
			@mkdir -p $(dir $@)
			@$(call run_and_test,$(CC) $(CFLAGS) -c $< -o $@)

clean:		header
			@rm -rf objs objs_tests
			@printf "%-53b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"

fclean:		header clean
			@rm -rf $(NAME)
			@rm -rf $(TEST_NAME)
			@printf "%-53b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"

re:			fclean all

.PHONY:		all clean fclean re libft header
