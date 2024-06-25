/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:11:46 by ssuchane          #+#    #+#             */
/*   Updated: 2024/06/25 12:32:18 by eaktimur         ###   ########.fr       */
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

void	populate1(int *num_and_flags, t_l **a_list)
{
	if (num_and_flags[1])
	{
		if (num_and_flags[2])
			num_and_flags[0] *= -1;
		if (check_doubles(*a_list, num_and_flags[0]))
			exit_error();
		populate_a(a_list, num_and_flags[0]);
		num_and_flags[1] = 0;
		num_and_flags[2] = 0;
	}
}

void	populate(char *str, char c, int *num_and_flags, t_l **a_list)
{
	while (*str)
	{
		if (*str == c)
			populate1(num_and_flags, a_list);
		else if (is_num(*str) || (*str == '-' && !num_and_flags[1]))
		{
			if (!num_and_flags[1])
			{
				num_and_flags[1] = 1;
				num_and_flags[0] = 0;
				if (*str == '-')
				{
					num_and_flags[2] = 1;
					str++;
					continue ;
				}
			}
			num_and_flags[0] = num_and_flags[0] * 10 + (*str - '0');
		}
		else
			exit_error();
		str++;
	}
}

void	ft_split(char **argv, char c, t_l **a)
{
	t_l		*a_list;
	char	*str;
	int		num_and_flags[3];

	a_list = NULL;
	num_and_flags[0] = 0;
	num_and_flags[1] = 0;
	num_and_flags[2] = 0;
	str = argv[1];
	populate(str, c, num_and_flags, &a_list);
	if (num_and_flags[1])
	{
		if (num_and_flags[2])
			num_and_flags[0] *= -1;
		if (check_doubles(a_list, num_and_flags[0]))
			exit_error();
		populate_a(&a_list, num_and_flags[0]);
	}
	*a = a_list;
}
