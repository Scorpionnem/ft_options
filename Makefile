NAME = libftgetopt.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES =	-I ./includes/

SRCS =	src/ft_getopt.c\
		src/options/options_add_back.c\
		src/options/ft_free_opt.c\
		src/options/options_last.c\
		src/options/options_new.c\
		src/options/options_size.c\
		src/args/args_add_back.c\
		src/args/args_free.c\
		src/args/args_last.c\
		src/args/args_new.c\
		src/args/args_size.c\
		src/utils.c

OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS = $(SRCS:%.c=$(OBJDIR)/%.d)

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	@echo Compiling $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo Compiling $<
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
	@echo Cleaning objects
	@rm -rf $(OBJDIR)

fclean: clean
	@echo Cleaning $(NAME)
	@rm -rf $(NAME)

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run

-include $(DEPS)
