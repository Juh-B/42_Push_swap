#include "../includes/push_swap.h"

// void ft_stack(t_list **stack, void *content)
// {
//   t_list  *new_node;

//   new_node = ft_lstnew(content);
//   if (new_node == NULL)
//     return ;
//   new_node->mov_a = 0;
//   new_node->mov_b = 0;
//   new_node->type_mov_a = '\0';
//   new_node->type_mov_b = '\0';
//   ft_lstadd_back(stack, new_node);
// }

static t_stack *ft_lstnew_push(void *content)
{
    t_stack *new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    new_node->mov_a = 0;
    new_node->mov_b = 0;
    new_node->type_mov_a = '\0';
    new_node->type_mov_b = '\0';
    return (new_node);
}

static void ft_lstadd_back_push(t_stack **lst, t_stack *new)
{
    t_stack *temp;

    if (!lst || !new)
        return;
    if (!*lst)
    {
        *lst = new;
        return;
    }
    temp = *lst;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

void ft_stack(t_stack **stack, void *content)
{
    t_stack *new_node;

    new_node = ft_lstnew_push(content);
    if (!new_node)
        return;
    ft_lstadd_back_push(stack, new_node);
}
