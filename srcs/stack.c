/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:05:00 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/10 13:42:24 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(void)
{
	t_stack *new;

	if (!(new = malloc(sizeof(t_stack *))))
		return (NULL);
	new->top = NULL;
	new->size = 0;
	return (new);
}

void	*pop(t_stack *stack)
{
	t_node	*node;
	void	*cont;

	if (!stack->top)
		return (NULL);
	node = (t_node *)malloc(sizeof(t_node));
	node = stack->top;
	cont = node->cont;
	stack->top = node->next;
	stack->size -= 1;
	free(node);
	return (cont);
}

void	push(t_stack *stack, void *cont)
{
	t_node *new;

	if (!(new = malloc(sizeof(t_node))))
		return ;
	new->cont = cont;
	if (stack->top)
		new->next = stack->top;
	else
		new->next = NULL;
	stack->top = new;
	stack->size += 1;
}

void	*peek(t_stack *stack)
{
	if (!stack->top)
		return (NULL);
	return (stack->top->cont);
}

int		is_empty(t_stack *stack)
{
	if (!stack->top || !stack->size)
		return (1);
	return (0);
}
