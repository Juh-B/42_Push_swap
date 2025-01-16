#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
  t_stack  *stack_a;
  t_stack  *stack_b;
  int code;

  stack_a = NULL;
  stack_b = NULL;
  code = verifications(argc, argv, &stack_a);
  if (code != 3)
  {
    if (code == 0)
      return (0);
    else
      return (ft_error(code));
  }
  order_by(&stack_a, &stack_b);
  ft_free(stack_a);
  return (0);
}
