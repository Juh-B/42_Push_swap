#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
  t_list  *stack_a;
  t_list  *stack_b;
  t_list  *moves;
  t_list  *current;
  int code;

  stack_a = NULL;
  stack_b = NULL;
  moves = NULL;
  code = verifications(argc, argv, &stack_a);
  if (code != 3)
  {
    if (code == 0)
      return (0);
    else
      return (ft_error(code));
  }
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
