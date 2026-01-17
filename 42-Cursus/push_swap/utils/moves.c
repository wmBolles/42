/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:24:44 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/25 10:48:56 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*curr;

	if (*b)
	{
		curr = *b;
		*b = (*b)->next;
		curr->next = *a;
		*a = curr;
		write(1, "pa\n", 3);
	}
}

void	pb(t_node **a, t_node **b)
{
	t_node	*curr;

	if (*a)
	{
		curr = *a;
		*a = (*a)->next;
		curr->next = *b;
		*b = curr;
		write(1, "pb\n", 3);
	}
}

void	ra(t_node **a, int check)
{
	t_node		*curr;

	if (ft_lstsize(*a) > 1)
	{
		curr = *a;
		*a = (*a)->next;
		last_node(curr)->next = curr;
		curr->next = NULL;
		if (check == 1)
			write(1, "ra\n", 3);
	}
}

void	rb(t_node **b, int check)
{
	t_node		*curr;

	if (ft_lstsize(*b) > 1)
	{
		curr = *b;
		*b = (*b)->next;
		last_node(curr)->next = curr;
		curr->next = NULL;
		if (check == 1)
			write(1, "rb\n", 3);
	}
}

void	rr(t_node **a, t_node **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
