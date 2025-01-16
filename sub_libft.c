#include "./push_swap.h"

//........LIBFT..............
// PROTOTIPADA
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// PROTOTIPADA
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
// PROTOTIPADA
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

// PROTOTIPADA
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


//.............LST.....................
// PROTOTIPADA
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

// PROTOTIPADA
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// PROTOTIPADA
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

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	new->next = *lst;
// 	*lst = new;
// }

// PROTOTIPADA
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


//.........ATOI......................
// PROTOTIPADA
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
