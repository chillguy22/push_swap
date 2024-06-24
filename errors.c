/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:11:42 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/24 17:07:56 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_free_list(t_l *list)
{
	t_l	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	exit(0);
}

void	exit_error(void)
{
	printf("Error\n");
	exit(0);
}

void	exit_error_free(t_l *stack)
{
	t_l	*tmp;

	printf("Error\n");
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	exit(0);
}

void	free_list(t_l *list)
{
	t_l	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
