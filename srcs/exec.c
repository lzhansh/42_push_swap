/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:05:30 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/14 18:37:59 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		exec_instr(t_stack *a, t_stack *b, char *str, int dis)
{
	if (ft_strequ(str, "sa"))
		sx(a, b, NULL, dis);
	else if (ft_strequ(str, "sb"))
		sx(b, a, NULL, (dis == 1 ? 2 : 0));
	else if (ft_strequ(str, "ss"))
		ss(a, b, NULL, dis);
	else if (ft_strequ(str, "pa"))
		px(a, b, NULL, dis);
	else if (ft_strequ(str, "pb"))
		px(b, a, NULL, (dis == 1 ? 2 : 0));
	else if (ft_strequ(str, "ra"))
		rx(a, b, NULL, dis);
	else if (ft_strequ(str, "rb"))
		rx(b, a, NULL, (dis == 1 ? 2 : 0));
	else if (ft_strequ(str, "rr"))
		rr(a, b, NULL, dis);
	else if (ft_strequ(str, "rra"))
		rrx(a, b, NULL, dis);
	else if (ft_strequ(str, "rrb"))
		rrx(b, a, NULL, (dis == 1 ? 2 : 0));
	else if (ft_strequ(str, "rrr"))
		rrr(a, b, NULL, dis);
	else
		return (0);
	return (1);
}

void	exec(t_stack *a, t_stack *b, int dis)
{
	char *str;

	while (get_next_line(0, &str) > 0)
		if (exec_instr(a, b, str, dis) == 0)
			print_error("Error");
}

void	free_stack(t_stack *a)
{
	if (!a->top)
		return ;
	a->top = NULL;
	a->size = 0;
}
