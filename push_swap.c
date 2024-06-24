/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:28:50 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/24 17:11:00 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_l **a)
{
	int	index;
	int	median;
	int	i;

	index = find_lowest(a);
	median = find_lowest2(a);
	i = 0;
	if (median == -1)
	{
		while (i < (stack_size(*a) - index))
		{
			reverse_rotate(a, 'a');
			i++;
		}
	}
	else if (median == 1)
	{
		while (i < index)
		{
			r(a, 'a');
			i++;
		}
	}
}

void	update_and_execute(t_l **a, t_l **b, t_l **to_push)
{
	update_indexes(a, b);
	update_targets(a, b);
	*to_push = push_cost(a, b);
	update_median(a);
	update_median(b);
	execute_operations(a, b, *to_push);
	push_a(a, b);
}

void	actual_push_swap(t_l **a, t_l **b)
{
	t_l	*to_push;

	while (stack_size(*a) >= 3)
	{
		if (stack_size(*a) > 3)
		{
			if (*a == find_highest(*a))
				r(a, 'a');
			push_b(a, b);
		}
		else
		{
			three_elem_sort(a);
			while (stack_size(*b) > 0)
			{
				update_and_execute(a, b, &to_push);
			}
		}
		if (stack_size(*b) == 0)
			break ;
	}
	update_median(a);
	final_rotate(a);
}

void	sizebased_operation(t_l **a, t_l **b)
{
	if (is_sorted(*a))
		exit_free_list(*a);
	if (stack_size(*a) == 2)
		two_elem_sort(*a);
	else if (stack_size(*a) == 3)
		three_elem_sort(a);
	else
		actual_push_swap(a, b);
}

int	main(int argc, char **argv)
{
	t_l	*a;
	t_l	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		ft_split(argv, ' ', &a);
	else if (argc > 2)
		handle_input(argv, argc, &a);
	update_indexes(&a, &b);
	sizebased_operation(&a, &b);
	exit_free_list(a);
	return (0);
}
