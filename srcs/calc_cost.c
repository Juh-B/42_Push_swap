#include "../includes/push_swap.h"

t_list  *calc_cost(t_list *stack_orig, t_list *stack_dest, char orig, char dest)
{
  long total;
  long lowest_total;
  t_list *lowest_cost;
  t_list *fit_in;

  mov_cost(stack_orig, orig);
  mov_cost(stack_dest, dest);
  lowest_total = 100000;
  while (stack_orig)
  {
    total = 1;
    if (orig == 'a')
      fit_in = fit_in_b(stack_orig, stack_dest);
    else
      fit_in = fit_in_a(stack_orig, stack_dest);
    total += mov_total(stack_orig, fit_in);
    if (lowest_total > total)
    {
      lowest_total = total;
      lowest_cost = stack_orig;
    }
    stack_orig = stack_orig->next;
  }
  return (lowest_cost);
}
