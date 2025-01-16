#ifndef LIBFT_H
#define LIBFT_H

// LIBs
#include <stdlib.h>
#include <stdio.h> // TEM QUE TIRAR

// Stack Structure
typedef struct s_list
{
  void *content;
  long mov_a;
  long mov_b;
  char type_mov_a;
  char type_mov_b;
  struct s_list *next;
} t_list;

// Functions
// PROTOTIPADA
int ft_error(int type);
// int verif_number(const char *str);
int verifications(int argc, char **argv, t_list **stack_a);
int  create_stack(int argc, char **argv, t_list **stack_a);
// int verify(t_list *stack, char type);
long mov_total(t_list *stack_a, t_list *stack_b);
void ft_stack(t_list **stack, void *content);
void ft_free(t_list *stack);
void order_by(t_list **stack_a, t_list **stack_b, t_list **moves);
void swap(t_list **stack);
void push(t_list **stack_orig, t_list **stack_dest);
void rotate(t_list **stack);
void rotate_rev(t_list **stack);
void tiny_sort(t_list **stack, t_list **lst);
void mov_cost(t_list *stack, char c);
void sort_stacks(t_list **stack_a, t_list **stack_b, t_list **lst);
void ft_move(t_list **stack_a, t_list **stack_b, t_list *node_a, t_list *node_b, t_list **lst);
t_list *find_lowest(t_list *stack);
t_list *find_highest(t_list *stack);
t_list *calc_cost(t_list *stack_orig, t_list *stack_dest, char orig, char dest);
t_list *fit_in_a(t_list *node_b, t_list *stack_a);
t_list *fit_in_b(t_list *node_a, t_list *stack_b);

// LIBFT
char **ft_split(char const *s, char c);
char *ft_strjoin(char const *s1, char const *s2);
int ft_atoi(const char *nptr);
int ft_isdigit(int c);
void *ft_memcpy(void *dest, const void *src, size_t n);
size_t ft_strlen(const char *s);

int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);

#endif
