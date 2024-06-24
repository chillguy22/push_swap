/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:55:34 by eaktimur          #+#    #+#             */
/*   Updated: 2024/06/21 16:58:01 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_l **a, t_l **b)
{
	t_l	*node_to_move;

	if (!b || !*b)
		return ;
	node_to_move = *b;
	*b = node_to_move->next;
	if (*b)
		(*b)->prev = NULL;
	node_to_move->next = *a;
	if (*a)
		(*a)->prev = node_to_move;
	node_to_move->prev = NULL;
	*a = node_to_move;
	write(1, "pa\n", 3);
	update_indexes(a, b);
}

void	push_b(t_l **a, t_l **b)
{
	t_l	*node_to_move;

	if (!a || !*a)
		return ;
	node_to_move = *a;
	*a = node_to_move->next;
	if (*a)
		(*a)->prev = NULL;
	node_to_move->next = *b;
	if (*b)
		(*b)->prev = node_to_move;
	node_to_move->prev = NULL;
	*b = node_to_move;
	write(1, "pb\n", 3);
	update_indexes(a, b);
}

void	ss(t_l **a, t_l **b)
{
	s(a, 'x');
	s(b, 'x');
	write(1, "ss\n", 3);
}
