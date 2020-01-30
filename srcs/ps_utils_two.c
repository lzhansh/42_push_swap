/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:05:16 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/14 18:51:17 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sp_a_ut(t_stack *a, t_stack *b, int dis)
{
	if (ps_get_max(b) == (int)b->top->cont)
		px(a, b, "pa", dis);
	else
	{
		if ((int)b->top->cont == 1 ||
			(int)b->top->cont == (int)(get_tail(a->top))->cont + 1)
		{
			px(a, b, "pa", dis);
			rx(a, b, "ra", dis);
		}
		else
			ps_rotate(b, a, dis);
	}
}

void	ps_split_a(t_stack *a, t_stack *b, int size, int dis)
{
	int	avg;

	avg = ps_get_avg(b);
	while (size-- > 0)
	{
		if (b->size < 13)
			ps_sp_a_ut(a, b, dis);
		else
		{
			if (avg <= (int)b->top->cont)
				px(a, b, "pa", dis);
			else
			{
				if ((int)b->top->cont == 1 ||
					(int)b->top->cont == (int)(get_tail(a->top))->cont + 1)
				{
					px(a, b, "pa", dis);
					rx(a, b, "ra", dis);
				}
				else
					rx(b, a, "rb", (dis == 1 ? 2 : 0));
			}
		}
	}
}
