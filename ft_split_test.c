/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:11:46 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/25 12:14:15 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_l *a, int n)
{
	t_l	*node;

	node = a;
	if (!a)
		return (0);
	while (node)
	{
		if (node->nbr == n)
			exit_error();
		node = node->next;
	}
	return (0);
}

void	populate(int *is_num_started, int *is_negative, int *num, t_l *a_list)
{
	if (*is_num_started)
	{
		if (*is_negative)
			*num *= -1;
		if (check_doubles(a_list, *num))
			exit_error();
		populate_a(&a_list, *num);
		*is_num_started = 0;
		*is_negative = 0;
	}
}


void	ft_split(char **argv, char c, t_l **a)
{
	t_l		*a_list;
	char	*str;
	int		*num;
	int		*is_num_started;
	int		*is_negative;

	a_list = NULL;
	*num = 0;
	*is_num_started = 0;
	*is_negative = 0;
	str = argv[1];
	while (*str)
	{
		if (*str == c)
			populate(is_num_started, is_negative, num, a_list);
		else if (is_num(*str) || (*str == '-' && !(*is_num_started)))
		{
			if (!(*is_num_started))
			{
				*is_num_started = 1;
				*num = 0;
				if (*str == '-')
				{
					*is_negative = 1;
					str++;
					continue ;
				}
			}
			*num = *num * 10 + (*str - '0');
		}
		else
			exit_error();
		str++;
	}
	if (*is_num_started)
	{
		if (*is_negative)
			*num *= -1;
		if (check_doubles(a_list, *num))
			exit_error();
		populate_a(&a_list, *num);
	}
	*a = a_list;
}
