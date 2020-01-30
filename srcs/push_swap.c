/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:04:45 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/14 18:49:53 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_simple(t_stack *a, t_stack *b, int dis)
{
	if (is_sorted(a))
		return ;
	if (a->size > 4)
		ps_simple_split(a, b, dis);
	ps_simple_sort(a, b, dis);
	ps_simple_sort_desc(a, b, dis);
	while (b->size > 0)
		px(a, b, "pa", dis);
}

void	ps(t_stack *a, t_stack *b, int dis)
{
	if (is_sorted(a))
		return ;
	ps_split_b(a, b, a->size, dis);
	ps_solve(a, b, dis);
	if (ps_get_size(a, ps_get_max(a)) >= 20)
	{
		ps_backtrack_sp(a, b, ps_get_max(a), dis);
		ps_backtrack_sp(a, b, ps_get_max(a), dis);
	}
	ps_backtrack(a, b, ps_get_max(a), dis);
}

int		main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	int		dis;

	if (ac > 1)
	{
		dis = 0;
		a = init();
		b = init();
		if (!get_arg(a, ac, av, &dis))
			print_error("Error");
		get_arg(b, ac, av, &dis);
		ps_sort_b(b);
		ps_rank(a, b);
		if (a->size <= 5)
			ps_simple(a, b, dis);
		else
			ps(a, b, dis);
		free_stack(a);
		free_stack(b);
	}
	return (0);
}
