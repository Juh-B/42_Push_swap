#include <stdio.h>
#include <stdlib.h>

//........LIBFT..............
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		len;
	size_t		i;
	size_t		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

//... Split libft.............
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

static size_t	ft_elem_array(const char *s, char c)
{
	size_t	i;
	size_t	array_len;
	int		word_control;

	i = 0;
	array_len = 0;
	word_control = 0;
	while (s[i])
	{
		if (s[i] != c && word_control == 0)
		{
			word_control = 1;
			array_len++;
		}
		else if (s[i] == c)
			word_control = 0;
		i++;
	}
	return (array_len);
}

static char	*ft_new_string(const char *str, unsigned int i, unsigned int start)
{
	size_t	str_len;
	char	*new_str;

	str_len = i - start;
	new_str = (char *)malloc((str_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, str, str_len);
	new_str[str_len] = '\0';
	return (new_str);
}

static void	ft_free_all(char **array, unsigned int j)
{
	while (j > 0)
		free(array[--j]);
	free(array);
}

static char	*ft_allocate_array(char **array, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			array[j] = ft_new_string(s + start, i, start);
			if (array[j] == NULL)
			{
				ft_free_all(array, j);
				return (NULL);
			}
			j++;
		}
		else
			i++;
	}
	return (*array);
}

char	**ft_split(char const *s, char c)
{
	size_t	array_len;
	char	**array;

	array_len = ft_elem_array(s, c);
	array = (char **)malloc((array_len + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array[array_len] = NULL;
	ft_allocate_array(array, s, c);
	return (array);
}


//............. STRUCT..................
typedef struct s_list
{
	void			    *content;
	struct s_list	*next;
}               t_list;

//.............LST.....................
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_p;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_p = ft_lstlast(*lst);
	last_p->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

//.......STACK..................
void create_stack(t_list **stack, void *content)
{
  t_list  *new_node;

  new_node = ft_lstnew(content);
  if (new_node == NULL)
    return ;
  ft_lstadd_back(stack, new_node);
}

//.........ATOI......................
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) > 0)
	{
		number = (number * 10) + (nptr[i] - '0');
		i++;
	}
	return (number * sign);
}

//.........VERIFICATIONS...............
int	verif_str(const char *str)
{
	int	i;
	int	sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
  number *= sign;
  if (str[i] == '\0' && (number >= -2147483648 && number <= 2147483647))
    return (1);
  else
    return (0);
}

int verif_double(t_list *stack)
{
  int numb;
  t_list *temp;

  numb = 0;
  while (stack)
  {
    numb = *(int *)stack->content;
    temp = stack;
    temp = temp->next;
    while (temp)
    {
      if (numb == *(int *)temp->content)
        return (1);
      temp = temp->next;
    }
    stack = stack->next;
  }
  free(temp);
  return (0);
}

int verif_ordem(t_list *stack)
{
  int numb;
  t_list *temp;

  numb = 0;
  while (stack)
  {
    numb = *(int *)stack->content;
    temp = stack;
    temp = temp->next;
    while (temp)
    {
      if (numb > *(int *)temp->content)
        return (1);
      temp = temp->next;
    }
    stack = stack->next;
  }
  free(temp);
  return (0);
}

//.........OPERATIONS..............

//............SWAP.................
void swap(t_list **stack)
{
  t_list *first;
  t_list *second;

  if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    return ;
  first = *stack;
  second = first->next;
  first->next = second->next;
  second->next = first;
  *stack = second;
}

//..........PUSH..................
void  push(t_list **stack_orig, t_list **stack_dest)
{
  t_list *orig;
  t_list *sec_orig;
  t_list *dest;


  if (stack_orig == NULL)
    return ;
  dest = *stack_dest;
  orig = *stack_orig;
  sec_orig = orig->next;
  orig->next = dest;
  *stack_orig = sec_orig;
  *stack_dest = orig;
}

//........ROTATE..................
void rotate(t_list **stack)
{
  t_list *first;
  t_list *second;
  t_list *last;

  if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    return ;
  first = *stack;
  second = first->next;
  last = ft_lstlast(*stack);
  first->next = NULL;
  last->next = first;
  *stack = second;
}

void rotate_rev(t_list **stack)
{
  t_list *before_last;
  t_list *last;

  if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    return ;
  last = *stack;
  while (last->next)
  {
    before_last = last;
    last = last->next;
  }
  before_last->next = NULL;
  last->next = *stack;
  *stack = last;
}

//........TINY SORT.................
t_list	*find_highest(t_list *stack)
{
	int				numb;
	t_list	*highest;

	if (NULL == stack)
		return (NULL);
	numb = -2147483648;
	while (stack)
	{
		if (*(int *)stack->content > numb)
		{
			numb = *(int *)stack->content;
			highest = stack;
		}
		stack = stack->next;
	}
	return (highest);
}

t_list	*find_lower(t_list *stack)
{
	int				numb;
	t_list	*lower;

	if (NULL == stack)
		return (NULL);
	numb = 2147483647;
	while (stack)
	{
		if (*(int *)stack->content < numb)
		{
			numb = *(int *)stack->content;
			lower = stack;
		}
		stack = stack->next;
	}
	return (lower);
}

void  tiny_sort(t_list **stack, t_list **lst)
{
	t_list	*highest;

	highest = find_highest(*stack);
	if (*stack == highest)
  {
		rotate(stack);
    create_stack(lst, "ra\n");
  }
	else if ((*stack)->next == highest)
  {
    rotate_rev(stack);
    create_stack(lst, "rra\n");
  }
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
  {
		swap(stack);
    create_stack(lst, "sa\n");
  }
}

void  tiny_sort_reverse(t_list **stack, t_list **lst)
{
	t_list	*lower;

	lower = find_lower(*stack);
	if (*stack == lower)
  {
		rotate(stack);
    create_stack(lst, "rb\n");
  }
	else if ((*stack)->next == lower)
  {
    rotate_rev(stack);
    create_stack(lst, "rrb\n");
  }
	if (*(int *)(*stack)->content < *(int *)(*stack)->next->content)
  {
		swap(stack);
    create_stack(lst, "sb\n");
  }
}

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

void quicksort_reverse(t_list **stack_1, t_list **stack_2, t_list **lst)
{
  int pivot;
  int push_count;
  int i;
  int size;

  size = ft_lstsize(*stack_1);
  if (size <= 1)
    return ;
  pivot = median(*stack_1, size);
  push_count = 0;
  i = 0;
  while (i < size)
  {
    if (*(int *)(*stack_1)->content > pivot)
    {
      push(stack_1, stack_2);
      create_stack(lst, "pa\n");
      push_count++;
    }
    else
    {
      rotate(stack_1);
      create_stack(lst, "rb\n");
    }
    i++;
  }
}

void quicksort(t_list **stack_1, t_list **stack_2, t_list **lst)
{
  int pivot;
  int push_count;
  int i;
  int size;

  size = ft_lstsize(*stack_1);
  if (size <= 1)
    return ;
  pivot = median(*stack_1, size);
  push_count = 0;
  i = 0;
  while (i < size)
  {
    if (*(int *)(*stack_1)->content < pivot)
    {
      push(stack_1, stack_2);
      create_stack(lst, "pb\n");
      push_count++;
    }
    else
    {
      rotate(stack_1);
      create_stack(lst, "ra\n");
    }
    i++;
  }
}

void  ord_stacks(t_list **stack_1, t_list **stack_2, t_list **lst)
{
  int push_count;

  while (ft_lstsize(*stack_1) > 3)
    quicksort(stack_1, stack_2, lst);
  if (ft_lstsize(*stack_1) <= 3)
    tiny_sort(stack_1, lst);
  while (ft_lstsize(*stack_2) > 3)
    quicksort_reverse(stack_2, stack_1, lst);
  if (ft_lstsize(*stack_2) <= 3)
    tiny_sort_reverse(stack_2, lst);
  push_count = ft_lstsize(*stack_2);
  while (push_count--)
  {
    push(stack_2, stack_1);
    create_stack(lst, "pa\n");
  }
}

//............MAIN.......................
int main(int argc, char **argv)
{
  int i;
  int size;
  int n;
  int *value;
  int *numb_b;
  char  *new_argv;
  t_list  *stack_a;
  t_list  *stack_b;
  t_list  *moves;
  t_list  *temp;
  t_list  *current;

  if (argc == 1 || (argc == 2 && argv[1] == ""))
  {
    printf("Invalid number of args\n");
    return (0);
  }
  else if (argc == 2)
  {
    new_argv = ft_strjoin("0 ", argv[1]);
    argv = ft_split(new_argv, ' ');
    free(new_argv);
  }
  size = 0;
  i = 1;
  stack_a = NULL;
  stack_b = NULL;
  moves = NULL;
  while (argv[i])
  {
    if (verif_str(argv[i]))
    {
      value = malloc(sizeof(int));
      if (!value)
      {
        printf("Error\n");
        return (1);
      }
      *value = ft_atoi(argv[i]);
      create_stack(&stack_a, value);
      i++;
    }
    else
    {
      printf("Error\n");
      return (1);
    }
  }

  if (verif_double(stack_a))
  {
    //LIBERAR A PILHA E RETORNAR ERROR
    printf("Error\n");
    current = stack_a;
    while (current)
    {
      temp = current;
      free(current->content);
      current = current->next;
      free(temp);
    }
    return (1);
  }

  if (!verif_ordem(stack_a))
    return (0);


  printf("---------ANTES----------\n");
  current = stack_a;
  printf("A......\n");
  while (current)
  {
    n = *(int *)current->content;
    printf("A. %d\n", n);
    current = current->next;
  }

  current = stack_b;
  printf("\nB........\n");
  while (current)
  {
    n = *(int *)current->content;
    printf("B...... %d\n", n);
    current = current->next;
  }

  printf("---------DEPOIS----------\n");

  size = ft_lstsize(stack_a);
  if (size == 2)
  {
    swap(&stack_a);
    create_stack(&moves, "sa\n");
  }
  else if (size == 3)
    tiny_sort(&stack_a, &moves);
  else
  {
    ord_stacks(&stack_a, &stack_b, &moves);
  }

  // swap(&stack_a);
  // rotate(&stack_a);
  // rotate_rev(&stack_a);
  // push(&stack_a, &stack_b);
  // quicksort(&stack_a, &stack_b, size, &moves);

  current = stack_a;
  printf("A......\n");
  while (current)
  {
    n = *(int *)current->content;
    printf("A. %d\n", n);
    current = current->next;
  }

  current = stack_b;
  printf("\nB........\n");
  while (current)
  {
    n = *(int *)current->content;
    printf("B...... %d\n", n);
    current = current->next;
  }

  printf("\n----------MOVES---------\n");
  char  *str;
  char  *str_next;
  int   count;
  count = 0;
  current = moves;
  while (current)
  {
    str = (char *)current->content;
    if (current->next != NULL)
      str_next = (char *)current->next->content;
    if ((str == "sa\n" && str_next == "sb\n") || (str == "sb\n" && str_next == "sa\n"))
    {
      printf("%s", "ss\n");
      current = current->next->next;
    }
    else if ((str == "ra\n" && str_next == "rb\n") || (str == "rb\n" && str_next == "ra\n"))
    {
      printf("%s", "rr\n");
      current = current->next->next;
    }
    else if ((str == "rra\n" && str_next == "rrb\n") || (str == "rrb\n" && str_next == "rra\n"))
    {
      printf("%s", "rrr\n");
      current = current->next->next;
    }
    else
    {
      printf("%s", str);
      current = current->next;
    }
    count++;
  }
  printf("\nN.de MOVS.... %d\n", count);

  //-------- LIMPEZA-------------
  current = stack_a;
  while (current)
	{
    temp = current;
		free(current->content);
		current = current->next;
		free(temp);
	}
  current = stack_b;
  while (current)
	{
    temp = current;
		free(current->content);
		current = current->next;
		free(temp);
	}

  // current = moves;
  // while (current)
	// {
  //   temp = current;
	// 	free(current->content);
	// 	current = current->next;
	// 	free(temp);
  //   // printf("limpando no\n");
	// }

  // free(value);
  // free(argv);
  return (0);
}
