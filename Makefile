NAME = push_swap
NAME_BONUS = checker

SRCDIR = srcs
OBJDIR = objs
INCDIR = includes
LIBFT_DIR = libft
BONUSDIR = bonus

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c calc_cost.c create_stack.c fit_in.c ft_free.c \
		ft_lst.c ft_rotate.c ft_stack.c low_or_hig_nbr.c move_stack.c \
		operations.c order_by.c sort_stacks.c tiny_sort.c verification.c

SRC_BONUS = checker_bonus.c checker_extra_bonus.c create_stack_bonus.c \
			get_command_bonus.c move_stack_bonus.c operations_bonus.c \
			verif_args_bonus.c verif_stack_bonus.c


OBJS = $(SRCS:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

GREEN = \033[1;32m
RESET = \033[0m

all: $(OBJDIR) $(NAME)

bonus: $(OBJDIR) $(NAME_BONUS)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(addprefix $(OBJDIR)/, $(OBJS)) $(LIBFT)
	@echo "$(GREEN)Push Swap is Ready!$(RESET)"

$(NAME_BONUS): $(addprefix $(OBJDIR)/, $(OBJ_BONUS))
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME_BONUS) $(addprefix $(OBJDIR)/, $(OBJ_BONUS)) $(LIBFT)
	@echo "$(GREEN)Checker is Ready! - Bonus$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(GREEN)Clean done!$(RESET)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(GREEN)Full clean done!$(RESET)"

re: fclean all

.PHONY: all clean fclean bonus re