#include "./push_swap.h"

//.........QUICK SORT..................

int find_median(int *numbers, int n_elem)
{
  int i;
  int j;
  int temp;

  i = 1;
  while (i <= n_elem)
  {
    j = 0;
    while (j < n_elem - i)
    {
      if (numbers[j] > numbers[j + 1])
      {
        temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
      }
      j++;
    }
    i++;
  }
  return (numbers[n_elem / 2]);
}

int median(t_list *stack, int size)
{
    int i;
    int *values;
    int median;
    t_list *temp;

    values = malloc(size * sizeof(int));
    temp = stack;
    i = 0;
    while (i < size)
    {
      values[i] = *(int *)temp->content;
      temp = temp->next;
      i++;
    }
    median = find_median(values, size);
    free(values);
    return (median);
}

int quicksort_reverse(t_list **stack_1, t_list **stack_2, t_list **lst)
{
  int pivot;
  int push_count;
  int i;
  int size;

  size = ft_lstsize(*stack_1);
  if (size <= 1)
    return (0);
  pivot = median(*stack_1, size);
  push_count = 0;
  i = 0;
  while (i < size)
  {
    if (*(int *)(*stack_1)->content > pivot)
    {
      push(stack_1, stack_2);
      ft_stack(lst, "pa\n");
      push_count++;
    }
    else
    {
      rotate(stack_1);
      ft_stack(lst, "rb\n");
    }
    i++;
  }
  return (push_count);
}

int quicksort(t_list **stack_1, t_list **stack_2, t_list **lst)
{
  int pivot;
  int push_count;
  int i;
  int size;

  size = ft_lstsize(*stack_1);
  if (size <= 1)
    return (0);
  pivot = median(*stack_1, size);
  push_count = 0;
  i = 0;
  while (i < size)
  {
    if (*(int *)(*stack_1)->content < pivot)
    {
      push(stack_1, stack_2);
      ft_stack(lst, "pb\n");
      push_count++;
    }
    else
    {
      rotate(stack_1);
      ft_stack(lst, "ra\n");
    }
    i++;
  }
  return (push_count);
}
