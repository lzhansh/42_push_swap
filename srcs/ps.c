/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:04:18 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/14 18:52:11 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_backtrack(t_stack *a, t_stack *b, int limit, int dis)
{
	while ((int)a->top->cont <= limit && (int)a->top->cont != 1)
	{
		if ((int)a->top->cont == (int)(get_tail(a->top))->cont + 1)
			rx(a, b, "ra", dis);
		else
			px(b, a, "pb", (dis == 1 ? 2 : 0));
	}
	if (ps_get_min(b) == (int)(get_tail(a->top))->cont + 1)
		ps_solve(a, b, dis);
}

void	ps_backtrack_sp(t_stack *a, t_stack *b, int limit, int dis)
{
	int	avg;
	int	count;
	int	i;

	count = 0;
	avg = ps_get_avg_limit(a, limit);
	while ((int)a->top->cont <= limit && (int)a->top->cont != 1)
	{
		if ((int)a->top->cont >= avg)
		{
			rx(a, b, "ra", dis);
			count++;
		}
		else
			px(b, a, "pb", (dis == 1 ? 2 : 0));
	}
	i = -1;
	while (++i < count)
		if ((int)b->top->cont != ps_get_min(b))
			rrr(a, b, "rrr", dis);
		else
			rrx(a, b, "rra", dis);
	if (ps_get_min(b) == (int)(get_tail(a->top))->cont + 1 && count > 0)
		ps_solve(a, b, dis);
}

void	ps_rotate(t_stack *a, t_stack *b, int dis)
{
	int		i;
	t_node	*tmp_a;

	tmp_a = a->top;
	i = 0;
	while (tmp_a->next && ++i)
	{
		if ((int)tmp_a->cont == ps_get_max(a))
			break ;
		tmp_a = tmp_a->next;
	}
	if ((int)a->size - i <= (int)a->size / 2)
		rrx(a, b, "rrb", (dis == 1 ? 2 : 0));
	else
		rx(a, b, "rb", (dis == 1 ? 2 : 0));
}

void	ps_split_b(t_stack *a, t_stack *b, int size, int dis)
{
	int		i;
	int		avg;

	avg = ps_get_avg(a);
	i = -1;
	while (++i < size)
	{
		if ((int)a->top->cont <= avg)
			px(b, a, "pb", (dis == 1 ? 2 : 0));
		else
			rx(a, b, "ra", dis);
	}
}

void	ps_solve(t_stack *a, t_stack *b, int dis)
{
	int max;

	if (!b->top)
		return ;
	max = ps_get_max(b);
	ps_split_a(a, b, b->size, dis);
	while (((int)a->top->cont == (int)(get_tail(a->top))->cont + 1 ||
		(int)a->top->cont == 1) && !is_sorted(a))
		rx(a, b, "ra", dis);
	ps_solve(a, b, dis);
	if (ps_get_size(a, max) >= 20)
		ps_backtrack_sp(a, b, max, dis);
	ps_backtrack(a, b, max, dis);
}
