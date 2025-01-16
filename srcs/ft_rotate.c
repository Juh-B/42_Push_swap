#include "../includes/push_swap.h"

static long same_rot(long *only_a, long *only_b, t_stack *n_a, t_stack *n_b)
{
  long  both;

  both = 0;
  if (n_a->mov_a <= n_b->mov_b)
  {
    both = n_a->mov_a;
    *only_a = 0;
    *only_b = n_b->mov_b - n_a->mov_a;
  }
  else
  {
    both = n_b->mov_b;
    *only_a = n_a->mov_a - n_b->mov_b;
    *only_b = 0;
  }
  return (both);
}

static void rot_both(long both, t_stack **stack_a, t_stack **stack_b, char c)
{
  while (both > 0)
  {
    rotate_both_stacks(stack_a, stack_b, c);
    both--;
  }
}

static void rot_a(long only_a, t_stack **stack_a, char c)
{
  while (only_a > 0)
  {
    if (c == 'u')
      rotate_stack(stack_a, 'a');
    else
      rotate_rev_stack(stack_a, 'a');
    only_a--;
  }
}

static void rot_b(long only_b, t_stack **stack_b, char c)
{
  while (only_b > 0)
  {
    if (c == 'u')
      rotate_stack(stack_b, 'b');
    else
      rotate_rev_stack(stack_b, 'b');
    only_b--;
  }
}


void	ft_rot(t_stack **st_a, t_stack **st_b, t_stack *n_a, t_stack *n_b)
{
  long  both;
  long  only_a;
  long  only_b;

  both = 0;
  only_a = n_a->mov_a;
  only_b = n_b->mov_b;
  if (n_a->type_mov_a == n_b->type_mov_b)
  {
    both = same_rot(&only_a, &only_b, n_a, n_b);
    rot_both(both, st_a, st_b, n_a->type_mov_a);
  }
  rot_a(only_a, st_a, n_a->type_mov_a);
  rot_b(only_b, st_b, n_b->type_mov_b);
}


// void  ft_move(t_stack **stack_a, t_stack **stack_b, t_stack *n_a, t_stack *n_b)
// {
//   long  both;
//   long  only_a;
//   long  only_b;

//   both = 0;
//   only_a = n_a->mov_a;
//   only_b = n_b->mov_b;
//   if (n_a->type_mov_a == n_b->type_mov_b)
//   {
//     both = same_rot(&only_a, &only_b, n_a, n_b);
//     rot_both(&both, stack_a, stack_b, n_a->type_mov_a);
//   }
//   // if (n_a->type_mov_a == n_b->type_mov_b)
//   // {
//   //   if (n_a->mov_a <= n_b->mov_b)
//   //   {
//   //     both = n_a->mov_a;
//   //     only_a = 0;
//   //     only_b = n_b->mov_b - n_a->mov_a;
//   //   }
//   //   else
//   //   {
//   //     both = n_b->mov_b;
//   //     only_a = n_a->mov_a - n_b->mov_b;
//   //     only_b = 0;
//   //   }
//   //   if (n_a->type_mov_a == 'u')
//   //   {
//   //     while (both > 0)
//   //     {
//   //       rotate(stack_a);
//   //       rotate(stack_b);
//   //       ft_printf("rr\n");
//   //       both--;
//   //     }
//   //   }
//   //   else
//   //   {
//   //     while (both > 0)
//   //     {
//   //       rotate_rev(stack_a);
//   //       rotate_rev(stack_b);
//   //       ft_printf("rrr\n");
//   //       both--;
//   //     }
//   //   }
//   // }
//   while (only_a > 0)
//   {
//     if (n_a->type_mov_a == 'u')
//     {
//       rotate(stack_a);
//       ft_printf("ra\n");
//     }
//     else
//     {
//       rotate_rev(stack_a);
//       ft_printf("rra\n");
//     }
//     only_a--;
//   }
//   while (only_b > 0)
//   {
//     if (n_b->type_mov_b == 'u')
//     {
//       rotate(stack_b);
//       ft_printf("rb\n");
//     }
//     else
//     {
//       rotate_rev(stack_b);
//       ft_printf("rrb\n");
//     }
//     only_b--;
//   }
// }
