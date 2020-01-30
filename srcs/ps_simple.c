/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:04:38 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/14 18:26:44 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_simple_rotate(t_stack *a, t_stack *b, int dis)
{
	int		i;
	t_node	*tmp;

	tmp = a->top;
	i = 0;
	while (tmp->next && ++i)
	{
		if ((int)tmp->cont == ps_get_min(a))
			break ;
		tmp = tmp->next;
	}
	if ((int)a->size - i <= (int)a->size / 2)
		rrx(a, b, "rra", dis);
	else
		rx(a, b, "ra", dis);
}

void	ps_simple_sort(t_stack *a, t_stack *b, int dis)
{
	t_node	*tmp;
	int		i;

	if (!a->top)
		return ;
	tmp = a->top;
	i = a->size;
	while (tmp->next != NULL && --i)
	{
		if ((int)a->top->next->cont == ps_get_min(a) &&
			(int)a->top->cont == ps_get_max(a))
			rx(a, b, "ra", dis);
		if (tmp->next && (int)tmp->next->cont < (int)tmp->cont)
		{
			while (i < a->size - 1 && i++)
				rx(a, b, "ra", dis);
			if ((int)a->top->next->cont == ps_get_min(a) &&
				(int)a->top->cont == ps_get_max(a))
				rx(a, b, "ra", dis);
			else
				sx(a, b, "sa", dis);
		}
		if (tmp->next)
			tmp = tmp->next;
	}
}

void	ps_simple_sort_desc(t_stack *a, t_stack *b, int dis)
{
	t_node	*tmp;
	int		i;

	if (!b->top)
		return ;
	tmp = b->top;
	i = b->size;
	while (tmp->next && --i)
	{
		if ((int)b->top->next->cont == ps_get_max(b) &&
			(int)b->top->cont == ps_get_min(b))
			rx(b, a, "rb", (dis == 1 ? 2 : 0));
		if (tmp->next && (int)tmp->next->cont > (int)tmp->cont)
		{
			while (i < b->size - 1 && i++)
				rx(b, a, "rb", (dis == 1 ? 2 : 0));
			if ((int)b->top->next->cont == ps_get_max(b) &&
				(int)b->top->cont == ps_get_min(b))
				rx(b, a, "rb", (dis == 1 ? 2 : 0));
			else
				sx(b, a, "sb", (dis == 1 ? 2 : 0));
		}
		if (tmp->next)
			tmp = tmp->next;
	}
}

void	ps_simple_split(t_stack *a, t_stack *b, int dis)
{
	int avg;

	avg = ps_get_avg(a);
	while (ps_get_min(a) < avg)
	{
		if ((int)a->top->cont < avg)
		{
			if ((int)(get_tail(a->top)->cont) + 1 == (int)a->top->cont)
			{
				ps_simple_rotate(a, b, dis);
				if (is_sorted(a))
					return ;
			}
			px(b, a, "pb", (dis == 1 ? 2 : 0));
		}
		else
			ps_simple_rotate(a, b, dis);
	}
}
