/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzhansha <lzhansha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:01:38 by lzhansha          #+#    #+#             */
/*   Updated: 2020/01/14 18:51:15 by lzhansha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

typedef struct		s_node {
	void			*cont;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack {
	int				size;
	struct s_node	*top;
}					t_stack;

typedef struct		s_inst {
	int				flag;
	int				dis;
}					t_ins;
/*
** stack.c
*/
t_stack				*init(void);
void				*pop(struct s_stack *stack);
void				push(struct s_stack *stack, void *cont);
void				*peek(struct s_stack *stack);
int					is_empty(struct s_stack *stack);
/*
** exec.c
*/
void				exec(t_stack *a, t_stack *b, int dis);
int					exec_instr(t_stack *a, t_stack *b, char *str, int dis);
/*
** instr			ucts.c
*/
void				sx(t_stack *stack, t_stack *s2, char *ins, int dis);
void				ss(t_stack *stack, t_stack *s2, char *ins, int dis);
void				px(t_stack *a, t_stack *b, char *instr, int dis);
void				rx(t_stack *st, t_stack *s2, char *ins, int dis);
void				rrx(t_stack *st, t_stack *s2, char *i, int dis);
void				rr(t_stack *st, t_stack *s2, char *ins, int dis);
void				rrr(t_stack *st, t_stack *s2, char *i, int dis);
/*
** print			.c
*/
void				print_error(char *msg);
void				print_stack(t_stack *a, t_stack *b);
/*
** utils			.c
*/
int					get_arg(t_stack *a, int args, char **av, int *dis);
int					is_repeated(t_stack *a, int num);
int					is_sorted(t_stack *a);
void				free_stack(t_stack *a);
t_node				*get_tail(t_node *top);
/*
** ps_utils.c
*/
int					ps_get_avg(t_stack *s);
int					ps_get_max(t_stack *s);
int					ps_get_size(t_stack *a, int limit);
int					ps_get_min(t_stack *s);
int					ps_get_avg_limit(t_stack *a, int limit);
/*
** ps_u	   t		ils_two.c
*/
void				ps_split_a(t_stack *a, t_stack *b, int s, int di);
/*
** ps_s	   o		rt.c
*/
t_node				*ps_parti(t_node *t, t_node *b, t_node **n, t_node **m);
t_node				*ps_quicksort(t_node *s, t_node *tail);
void				ps_sort_b(t_stack *s);
void				ps_rank(t_stack *a, t_stack *b);
/*
** ps_s	   i		mple.c
*/
void				ps_simple_rotate(t_stack *a, t_stack *b, int dis);
void				ps_simple_split(t_stack *a, t_stack *b, int dis);
void				ps_simple_sort(t_stack *a, t_stack *b, int dis);
void				ps_simple_sort_desc(t_stack *a, t_stack *b, int dis);
/*
** ps.c
*/
void				ps_backtrack(t_stack *a, t_stack *b, int limit, int dis);
void				ps_backtrack_sp(t_stack *a, t_stack *b, int limit, int dis);
void				ps_solve(t_stack *a, t_stack *b, int dis);
void				ps_rotate(t_stack *a, t_stack *b, int dis);
void				ps_split_b(t_stack *a, t_stack *b, int s, int di);
#endif
