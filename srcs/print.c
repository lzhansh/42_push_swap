/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:04:26 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/14 18:43:05 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_node *n_a;
	t_node *n_b;

	if (!a->top && !b->top)
		return ;
	n_a = a->top;
	n_b = b->top;
	ft_printf("-------------------\n");
	while (n_a || n_b)
	{
		if (n_a && n_b)
			ft_printf("%d		%d\n", (int)n_a->cont, (int)n_b->cont);
		else if (!n_b)
			ft_printf("%d   \n", (int)n_a->cont);
		else
			ft_printf(" 		%d\n", (int)n_b->cont);
		n_a = (n_a ? n_a->next : NULL);
		n_b = (n_b ? n_b->next : NULL);
	}
	ft_printf("---		---\nA		B \n-------------------\n");
}

void	print_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}
