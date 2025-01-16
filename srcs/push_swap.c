#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
  // int i;
  // int *value;
  t_list  *stack_a;
  t_list  *stack_b;
  t_list  *moves;
  t_list  *current;
  // int n;

  // if (argc == 1)
  //   return (ft_error(1));
  // else if (argc == 2 && argv[1][0] == '\0')
  //   return (ft_error(2));
  // int i = 0;
  // while (argv[1][i])
  //   {
  //     printf("n. %d\n", argv[1][i]);
  //     i++;
  //   }
  //   return (0);
  stack_a = NULL;
  stack_b = NULL;
  moves = NULL;
  int code;
  code = verifications(argc, argv, &stack_a);
  if (code != 3)
  {
    if (code == 0)
      return (0);
    else
      return (ft_error(code));
  }

  // verif = verifications(argc, argv, stack_a);
  // i = 1;
  // while (argv[i])
  // {
  //   if (verif_number(argv[i]))
  //   {
  //     value = malloc(sizeof(int));
  //     if (!value)
  //     {
  //       ft_free(stack_a);
  //       return (ft_error(2));
  //     }
  //     *value = ft_atoi(argv[i]);
  //     ft_stack(&stack_a, value);
  //     i++;
  //   }
  //   else
  //     return (ft_error(2));
  // }
  // if (verify(stack_a, 'd'))
  // {
  //   ft_free(stack_a);
  //   printf("Double\n");
  //   return (ft_error(2));
  // }
  // if (!verify(stack_a, 'o'))
  // {
  //   ft_free(stack_a);
  //   printf("Alredy ordered\n");
  //   return (0);
  // }
  current = stack_a;
  printf("...STACK A...\n");
  while (current)
  {
    printf("n. %d\n", *(int *)current->content);
    current = current->next;
  }

  order_by(&stack_a, &stack_b, &moves);

  printf("\n-------------\n");
  current = stack_a;
  printf("\n...STACK A...\n");
  while (current)
  {
    printf("n. %d\n", *(int *)current->content);
    current = current->next;
  }

  current = stack_b;
  printf("\n...STACK B...\n");
  while (current)
  {
    printf("n. %d\n", *(int *)current->content);
    current = current->next;
  }

  int count = 0;
  printf("\n....MOVES.....\n");
  current = moves;
  while (current)
  {
    printf("n. %s", (char *)current->content);
    current = current->next;
    count++;
  }
  printf("\nmoves. %d\n", count);

  ft_free(stack_a);
  return (0);
}
