#include "../includes/push_swap.h"


static int verify(t_stack *stack, char type)
{
  int numb;
  t_stack *temp;

  numb = 0;
  while (stack)
  {
    numb = *(int *)stack->content;
    temp = stack;
    if (stack->next != NULL)
    {
      temp = temp->next;
      while (temp)
      {
        if (type == 'd' && numb == *(int *)temp->content)
          return (1);
        else if (type == 'o' && numb > *(int *)temp->content)
          return (1);
        temp = temp->next;
      }
    }
    stack = stack->next;
  }
  return (0);
}

static int verif_order_and_double(t_stack *stack)
{
  if (verify(stack, 'd'))
  {
    ft_free(stack);
    printf("Double\n");
    return (2);
  }
  if (!verify(stack, 'o'))
  {
    ft_free(stack);
    printf("Alredy ordered\n");
    return (0);
  }
  return (3);
}

static int verif_args(int argc, char **argv)
{
  if (argc == 1)
    return (1);
  else if (argc == 2 && !argv[1][0])
    return (2);
  else
    return (3);
}

// int  create_stack(char **argv, t_stack *stack_a)
// {
//   int i;
//   int *value;

//   i = 1;
//   while (argv[i])
//   {
//     if (verif_number(argv[i]))
//     {
//       value = malloc(sizeof(int));
//       if (!value)
//       {
//         ft_free(stack_a);
//         return (ft_error(2));
//       }
//       *value = ft_atoi(argv[i]);
//       ft_stack(&stack_a, value);
//     }
//     else
//       return (ft_error(2));
//     i++;
//   }
//   return (3);
// }

int verifications(int argc, char **argv, t_stack **stack_a)
{
  int verif_1;
  int verif_2;
  int verif_stack;

  verif_1 = verif_args(argc, argv);
  if (verif_1 != 3)
  {
    if (verif_1 == 1)
      return (1);
    else
      return (2);
  }
  verif_stack = create_stack(argc, argv, stack_a);
  if (verif_stack == 2)
      return (2);
  verif_2 = verif_order_and_double(*stack_a);
  if (verif_2 != 3)
  {
    if (verif_2 == 2)
      return (2);
    else
      return (0);
  }
  return (3);
}
