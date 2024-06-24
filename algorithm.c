/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:11:38 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/24 17:14:24 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_l	*push_cost(t_l **a_node, t_l **b_node)
{
	t_l	*b;
	t_l	*a;
	t_l	*cheapest;
	int	min_cost;
	int	temp;

	b = *b_node;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (b != NULL)
	{
		a = b->target_node;
		b->push_cost = 0;
		temp = a->index + b->index;
		if (b->index + (stack_size(*a_node) - a->index) < temp)
			temp = b->index + (stack_size(*a_node) - a->index);
		if (a->index + (stack_size(*b_node) - b->index) < temp)
			temp = a->index + (stack_size(*b_node) - b->index);
		if ((stack_size(*a_node) - a->index) + (stack_size(*b_node)
				- b->index) < temp)
			temp = (stack_size(*a_node) - a->index) + (stack_size(*b_node)
					- b->index);
		b->push_cost = temp;
		if (b->push_cost < min_cost)
		{
			min_cost = b->push_cost;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}

void	execute_operations1(t_l **a, t_l **b, t_l *to_push, t_l *target)
{
	while (to_push->index > 0)
	{
		if (to_push->median == 1)
			r(b, 'b');
		else if (to_push->median == -1)
			reverse_rotate(b, 'b');
	}
	while (target->index > 0)
	{
		if (target->median == 1)
			r(a, 'a');
		else if (target->median == -1)
			reverse_rotate(a, 'a');
	}
}

void	execute_operations(t_l **a, t_l **b, t_l *to_push)
{
	t_l	*target;

	target = to_push->target_node;
	while (to_push->index > 0 && target->index > 0)
	{
		if (to_push->median == 1 && target->median == 1)
			rr(a, b);
		else if (to_push->median == -1 && target->median == -1)
			rrr(a, b);
		else
			break ;
	}
	execute_operations1(a, b, to_push, target);
}

int	find_lowest(t_l **stack)
{
	t_l	*lowest;
	t_l	*current;

	lowest = *stack;
	current = *stack;
	while (current != NULL)
	{
		if (current->nbr < lowest->nbr)
			lowest = current;
		current = current->next;
	}
	return (lowest->index);
}

int	find_lowest2(t_l **stack)
{
	t_l	*lowest;
	t_l	*current;

	lowest = *stack;
	current = *stack;
	while (current != NULL)
	{
		if (current->nbr < lowest->nbr)
			lowest = current;
		current = current->next;
	}
	return (lowest->median);
}
