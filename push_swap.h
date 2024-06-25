/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaktimur <eaktimur@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:07:28 by eaktimur          #+#    #+#             */
/*   Updated: 2024/06/25 12:29:26 by eaktimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct a_list
{
	int				nbr;
	int				index;
	int				push_cost;
	int				median;
	struct a_list	*target_node;
	struct a_list	*next;
	struct a_list	*prev;
}					t_l;

// op_push
void				push_a(t_l **a, t_l **b);
void				push_b(t_l **a, t_l **b);

// op_rotate
void				r(t_l **b, char which);
void				rr(t_l **a, t_l **b);
void				reverse_rotate(t_l **stack, char which);
void				rrr(t_l **a, t_l **b);

// op_swap
void				s(t_l **stack, char which);
void				ss(t_l **a, t_l **b);

// algorithm
t_l					*push_cost(t_l **a_node, t_l **b_node);
void				execute_operations1(t_l **a, t_l **b, t_l *to_push,
						t_l *target);
void				execute_operations(t_l **a, t_l **b, t_l *to_push);
int					find_lowest(t_l **stack);
int					find_lowest2(t_l **stack);

// errors
void				exit_free_list(t_l *list);
void				exit_error(void);
void				exit_error_free(t_l *stack);
void				free_list(t_l *list);

// ft_split
void	populate1(int *num_and_flags, t_l **a_list);
void	populate(char *str, char c, int *num_and_flags, t_l **a_list);
int					check_doubles(t_l *a, int n);
void				ft_split(char **argv, char c, t_l **a);

//	handle_input
void				handle_input(char **argv, int argc, t_l **a);
int					stack_size(t_l *a);
t_l					*find_highest(t_l *head);

// push_swap
void				final_rotate(t_l **a);
void				update_and_execute(t_l **a, t_l **b, t_l **to_push);
void				actual_push_swap(t_l **a, t_l **b);
void				sizebased_operation(t_l **a, t_l **b);
int					main(int argc, char **argv);

// setup
t_l					*find_last_node(t_l *a);
void				populate_a(t_l **a, int n);
int					ft_atoi(char *str);
int					is_num(char c);
int					is_sign(char c);

//	sort
int					is_sorted(t_l *a);
void				two_elem_sort(t_l *a);
void				three_elem_sort(t_l **a);

//	update
void				update_indexes(t_l **a, t_l **b);
void				update_targets(t_l **a, t_l **b);
void				update_median(t_l **stack);

#endif
