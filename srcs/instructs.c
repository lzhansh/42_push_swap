/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:03:58 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/14 18:44:57 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack *stack, t_stack *s2, char *instr, int dis)
{
	void *tmp;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		tmp = peek(stack);
		stack->top->cont = stack->top->next->cont;
		stack->top->next->cont = tmp;
	}
	instr == NULL ? 0 : ft_printf("%s\n", instr);
	dis == 1 ? print_stack(stack, s2) : 0;
	dis == 2 ? print_stack(s2, stack) : 0;
}

void	ss(t_stack *stack, t_stack *s2, char *instr, int dis)
{
	void *tmp;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		tmp = peek(stack);
		stack->top->cont = stack->top->next->cont;
		stack->top->next->cont = tmp;
	}
	if (s2->top != NULL && s2->top->next != NULL)
	{
		tmp = peek(s2);
		s2->top->cont = s2->top->next->cont;
		s2->top->next->cont = tmp;
	}
	instr == NULL ? 0 : ft_printf("%s\n", instr);
	dis == 1 ? print_stack(stack, s2) : 0;
	dis == 2 ? print_stack(s2, stack) : 0;
}

void	px(t_stack *a, t_stack *b, char *instr, int dis)
{
	t_node *tmp;

	if (!(tmp = malloc(sizeof(t_node))) || !b->top)
		return ;
	tmp->cont = pop(b);
	if (a->top)
		tmp->next = a->top;
	else
		tmp->next = NULL;
	a->top = tmp;
	a->size += 1;
	instr == NULL ? 0 : ft_printf("%s\n", instr);
	dis == 1 ? print_stack(a, b) : 0;
	dis == 2 ? print_stack(b, a) : 0;
}

void	rx(t_stack *st, t_stack *s2, char *instr, int dis)
{
	t_node *tmp;
	t_node *tmp2;

	if (st->top && st->top->next)
	{
		tmp2 = st->top;
		tmp = get_tail(st->top);
		st->top = tmp2->next;
		tmp2->next = NULL;
		tmp->next = tmp2;
	}
	instr == NULL ? 0 : ft_printf("%s\n", instr);
	dis == 1 ? print_stack(st, s2) : 0;
	dis == 2 ? print_stack(s2, st) : 0;
}

void	rr(t_stack *st, t_stack *s2, char *instr, int dis)
{
	t_node *tmp;
	t_node *tmp2;

	if (st->top && st->top->next)
	{
		tmp2 = st->top;
		tmp = get_tail(st->top);
		st->top = tmp2->next;
		tmp2->next = NULL;
		tmp->next = tmp2;
	}
	if (s2->top && s2->top->next)
	{
		tmp2 = s2->top;
		tmp = get_tail(s2->top);
		s2->top = tmp2->next;
		tmp2->next = NULL;
		tmp->next = tmp2;
	}
	instr == NULL ? 0 : ft_printf("%s\n", instr);
	dis == 1 ? print_stack(st, s2) : 0;
	dis == 2 ? print_stack(s2, st) : 0;
}
