/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:05:57 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/25 10:49:55 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a, int check)
{
	t_node	*before_last;
	t_node	*last;

	if (*a && ft_lstsize(*a) > 1)
	{
		before_last = *a;
		last = last_node(*a);
		while (before_last->next != last)
			before_last = before_last->next;
		before_last->next = NULL;
		last->next = *a;
		*a = last;
		if (check == 1)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_node **b, int check)
{
	t_node	*before_last;
	t_node	*last;

	if (*b && ft_lstsize(*b) > 1)
	{
		before_last = *b;
		last = last_node(*b);
		while (before_last->next != last)
			before_last = before_last->next;
		before_last->next = NULL;
		last->next = *b;
		*b = last;
		if (check == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_node **a, t_node **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}

void	sa(t_node **a, int check)
{
	int		swap;

	if (ft_lstsize(*a) > 1)
	{
		swap = (*a)->digit;
		(*a)->digit = (*a)->next->digit;
		(*a)->next->digit = swap;
		if (check == 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_node **b, int check)
{
	int		swap;

	if (ft_lstsize(*b) > 1)
	{
		swap = (*b)->digit;
		(*b)->digit = (*b)->next->digit;
		(*b)->next->digit = swap;
		if (check == 1)
			write(1, "sb\n", 3);
	}
}
