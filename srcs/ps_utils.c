/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:05:16 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/10 14:13:09 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_get_avg(t_stack *s)
{
	float	total;
	t_node	*tmp;

	if (s->size == 0)
		return (0);
	tmp = s->top;
	total = (int)tmp->cont;
	while (tmp->next)
	{
		total += (int)tmp->next->cont;
		tmp = tmp->next;
	}
	return ((int)(total / (int)s->size));
}

int		ps_get_max(t_stack *s)
{
	int		max;
	t_node	*tmp;

	if (s->size == 0)
		return (0);
	tmp = s->top;
	max = (int)tmp->cont;
	while (tmp->next)
	{
		if (max < (int)tmp->next->cont)
			max = (int)tmp->next->cont;
		tmp = tmp->next;
	}
	return (max);
}

int		ps_get_min(t_stack *s)
{
	int		min;
	t_node	*tmp;

	if (s->size == 0)
		return (0);
	tmp = s->top;
	min = (int)tmp->cont;
	while (tmp->next)
	{
		if (min > (int)tmp->next->cont)
			min = (int)tmp->next->cont;
		tmp = tmp->next;
	}
	return (min);
}

int		ps_get_size(t_stack *a, int limit)
{
	int		i;
	t_node	*tmp_a;

	if (!a->top)
		return (0);
	i = 0;
	tmp_a = a->top;
	while ((int)tmp_a->cont <= limit &&
		(int)tmp_a->cont != 1 && ++i)
		tmp_a = tmp_a->next;
	return (i);
}

int		ps_get_avg_limit(t_stack *a, int limit)
{
	float	total;
	t_node	*tmp_a;
	int		i;

	if (!a->top)
		return (0);
	i = 0;
	total = 0;
	tmp_a = a->top;
	while ((int)tmp_a->cont <= limit &&
		(int)tmp_a->cont != 1 && ++i)
	{
		total += (int)tmp_a->cont;
		tmp_a = tmp_a->next;
	}
	return ((int)(total / i));
}
