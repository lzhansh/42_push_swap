/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:04:51 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/15 17:10:08 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *a)
{
	t_node *tmp;

	if (!(tmp = malloc(sizeof(t_node))) || !a->top)
		return (0);
	tmp = a->top;
	while (tmp->next)
	{
		if ((int)tmp->cont > (int)tmp->next->cont)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		is_repeated(t_stack *a, int num)
{
	t_node *tmp;

	if (!a->top)
		return (0);
	tmp = a->top;
	while (tmp)
	{
		if ((int)tmp->cont == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		is_maxint(char *str)
{
	long int	value;
	int			sign;

	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		value = value * 10 + (*str - '0');
		str++;
	}
	if ((value * sign) <= 2147483647 && (value * sign) >= -2147483648)
		return (0);
	else
		return (1);
}

int		get_arg(t_stack *a, int args, char **av, int *dis)
{
	int tmp;
	int	flag;
	int num;

	flag = 0;
	num = 0;
	if (ft_strcmp("-v", av[1]) == 0 && (num = 1))
		*dis = 1;
	else if (args == 2)
	{
		args = ft_wordcount(av[1], ' ');
		av = ft_strsplit(av[1], ' ');
		flag = 1;
	}
	while (flag == 1 ? --args >= num : --args > num)
	{
		tmp = (int)ft_atoi(av[args]);
		if (
			!is_repeated(a, tmp) && !is_maxint(av[args]))
			push(a, (void *)(size_t)tmp);
		else
			return (0);
	}
	return (1);
}

t_node	*get_tail(t_node *top)
{
	t_node *tail;

	tail = top;
	while (tail && tail->next)
		tail = tail->next;
	return (tail);
}
