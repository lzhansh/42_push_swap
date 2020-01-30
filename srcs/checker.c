/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:38:08 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/15 17:02:10 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (get_arg(a, ac, av, &dis) != 1)
			print_error("Error");
		if (!is_empty(a))
			exec(a, b, dis);
		if (is_empty(b) && !is_empty(a) && is_sorted(a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stack(a);
		free_stack(b);
	}
	return (0);
}
