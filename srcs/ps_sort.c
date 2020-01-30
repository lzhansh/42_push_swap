/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:05:10 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/10 14:38:36 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_parti_help(t_node **prev, t_node **cur, t_node **end)
{
	t_node *tmp;

	tmp = NULL;
	if (*prev)
		(*prev)->next = (*cur)->next;
	tmp = (*cur)->next;
	(*cur)->next = NULL;
	(*end)->next = (*cur);
	(*end) = (*cur);
	(*cur) = tmp;
}

t_node	*ps_parti(t_node *top, t_node *tail,
		t_node **new_top, t_node **new_tail)
{
	t_node *pivot;
	t_node *prev;
	t_node *cur;
	t_node *end;

	pivot = tail;
	prev = NULL;
	cur = top;
	end = pivot;
	while (cur != pivot)
	{
		if ((int)cur->cont < (int)pivot->cont)
		{
			if ((*new_top) == NULL)
				(*new_top) = cur;
			prev = cur;
			cur = cur->next;
		}
		else
			ps_parti_help(&prev, &cur, &end);
	}
	if ((*new_top) == NULL)
		(*new_top) = pivot;
	(*new_tail) = end;
	return (pivot);
}

t_node	*ps_quicksort(t_node *top, t_node *tail)
{
	t_node *pivot;
	t_node *new_top;
	t_node *new_tail;
	t_node *tmp;

	new_top = NULL;
	new_tail = NULL;
	if (!top || top == tail)
		return (top);
	pivot = ps_parti(top, tail, &new_top, &new_tail);
	if (new_top != pivot)
	{
		tmp = new_top;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		new_top = ps_quicksort(new_top, tmp);
		tmp = get_tail(new_top);
		tmp->next = pivot;
	}
	pivot->next = ps_quicksort(pivot->next, new_tail);
	return (new_top);
}

void	ps_sort_b(t_stack *s)
{
	s->top = ps_quicksort(s->top, get_tail(s->top));
	return ;
}

void	ps_rank(t_stack *a, t_stack *b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		i;

	tmp_a = a->top;
	while (tmp_a)
	{
		tmp_b = b->top;
		i = 0;
		while (tmp_b && ++i)
		{
			if ((int)tmp_a->cont == (int)tmp_b->cont &&
				(int)tmp_b->cont != 898989)
			{
				tmp_b->cont = (void *)(size_t)898989;
				break ;
			}
			tmp_b = tmp_b->next;
		}
		tmp_a->cont = (void *)(size_t)i;
		tmp_a = tmp_a->next;
	}
	free_stack(b);
	b = init();
}
