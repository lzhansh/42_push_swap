/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:03:58 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/14 18:51:45 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx_help(t_stack *s)
{
	t_node *tmp;
	t_node *tmp2;

	tmp = s->top;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	tmp->next = s->top;
	s->top = tmp;
}

void	rrx(t_stack *st, t_stack *s2, char *instr, int dis)
{
	if (st->top && st->top->next)
		rrx_help(st);
	instr == NULL ? 0 : ft_printf("%s\n", instr);
	dis == 1 ? print_stack(st, s2) : 0;
	dis == 2 ? print_stack(s2, st) : 0;
}

void	rrr(t_stack *st, t_stack *s2, char *instr, int dis)
{
	if (st->top && st->top->next)
		rrx_help(st);
	if (s2->top && s2->top->next)
		rrx_help(s2);
	instr == NULL ? 0 : ft_printf("%s\n", instr);
	dis == 1 ? print_stack(st, s2) : 0;
	dis == 2 ? print_stack(s2, st) : 0;
}
