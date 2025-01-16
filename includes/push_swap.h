#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// LIBs
#include <stdlib.h>
#include <stdio.h> // TEM QUE TIRAR
#include "../libft/libft.h"

// Stack Structure
typedef struct s_stack
{
  void *content;
  long mov_a;
  long mov_b;
  char type_mov_a;
  char type_mov_b;
  struct s_stack *next;
} t_stack;

// Functions
// PROTOTIPADA
int ft_error(int type);
int verifications(int argc, char **argv, t_stack **stack_a);
int  create_stack(int argc, char **argv, t_stack **stack_a);
int	ft_lst_size(t_stack *lst);
long  mov_total(t_stack *stack_a, t_stack *stack_b);
void ft_stack(t_stack **stack, void *content);
void ft_free(t_stack *stack);
void order_by(t_stack **stack_a, t_stack **stack_b, t_stack **moves);
void swap(t_stack **stack);
void push(t_stack **stack_orig, t_stack **stack_dest);
void rotate(t_stack **stack);
void rotate_rev(t_stack **stack);
void tiny_sort(t_stack **stack, t_stack **lst);
void mov_cost(t_stack *stack, char c);
void sort_stacks(t_stack **stack_a, t_stack **stack_b, t_stack **lst);
void ft_move(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b, t_stack **lst);
t_stack	*ft_lst_last(t_stack *lst);
t_stack *find_lowest(t_stack *stack);
t_stack *find_highest(t_stack *stack);
t_stack *calc_cost(t_stack *stack_orig, t_stack *stack_dest, char orig, char dest);
t_stack *fit_in_a(t_stack *node_b, t_stack *stack_a);
t_stack *fit_in_b(t_stack *node_a, t_stack *stack_b);


// // LIBFT
char **ft_split(char const *s, char c);
char *ft_strjoin(char const *s1, char const *s2);
int ft_atoi(const char *nptr);
int ft_isdigit(int c);
void *ft_memcpy(void *dest, const void *src, size_t n);
size_t ft_strlen(const char *s);

#endif
