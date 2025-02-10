NAME = push_swap

SRCDIR = srcs
OBJDIR = objs
INCDIR = includes
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(SRCDIR)/push_swap.c\
	$(SRCDIR)/calc_cost.c\
	$(SRCDIR)/create_stack.c\
	$(SRCDIR)/fit_in.c\
	$(SRCDIR)/ft_free.c\
	$(SRCDIR)/ft_lst.c\
	$(SRCDIR)/ft_rotate.c\
	$(SRCDIR)/ft_stack.c\
	$(SRCDIR)/low_or_hig_nbr.c\
	$(SRCDIR)/move_stack.c\
	$(SRCDIR)/operations.c\
	$(SRCDIR)/order_by.c\
	$(SRCDIR)/sort_stacks.c\
	$(SRCDIR)/tiny_sort.c\
	$(SRCDIR)/verification.c\

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re