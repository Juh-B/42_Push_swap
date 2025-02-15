#include "../includes/checker.h"

static int verif_input(char *cmd)
{
  if ((cmd[1] == 'a' || cmd[1]== 'b' || cmd[1] == 's') && cmd[2] == '\n')
  {
    if (cmd[1] == 'a' || cmd[1]== 'b')
    {
      if (cmd[0] == 'p' || cmd[0]== 's' || cmd[0]== 'r')
        return (1);
    }
    else
    {
      if (cmd[0]== 's')
        return (1);
    }
  }
  else if (cmd[0]== 'r' && cmd[1] == 'r' && cmd[2] == '\n')
    return (1);
  else if (cmd[0]== 'r' && cmd[1] == 'r' && cmd[2] != '\n' && cmd[3] == '\n')
  {
    if (cmd[2] == 'a' || cmd[2] == 'b' || cmd[2] == 'r')
      return (1);
  }
  return (0);
}

static int  process_command(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
  if (verif_input(cmd))
  {
    if (cmd[2] == '\n')
    {
      if (cmd[1] == 'a' || cmd[1]== 'b')
      {
        if (cmd[0] == 'p')
          push_stack(stack_a, stack_b, cmd);
        else if (cmd[0] == 's')
          swap_stack(stack_a, stack_b, cmd);
        else if (cmd[0] == 'r')
          rotate_stack(stack_a, stack_b, cmd);
      }
      else if (cmd[0] == 's' && cmd[1] == 's')
        swap_stack(stack_a, stack_b, cmd);
      else if (cmd[0] == 'r' && cmd[1] == 'r')
        rotate_stack(stack_a, stack_b, cmd);
    }
    else if (cmd[2] != '\n' && cmd[3] == '\n')
      rotate_rev_stack(stack_a, stack_b, cmd);
  }
  else
    return (1);
  return (0);
}

int get_command(t_stack **stack_a, t_stack **stack_b)
{
  char  *cmd;

  while ((cmd = get_next_line(0)))
  {
      if (process_command(stack_a, stack_b, cmd))
      {
        ft_printf("Error\n");
        ft_free_all(*stack_a, *stack_b);
        free(cmd);
        return (1);
      }
      free(cmd);
  }
  return (0);
}
