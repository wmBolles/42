/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 02:16:22 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/26 00:19:53 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_node *a)
{
	while (a)
	{
		if (a->next != NULL && a->digit > a->next->digit)
			return (0);
		a = a->next;
	}
	return (1);
}

void	get_index(t_node *a)
{
	int		index;

	index = 0;
	if (!a)
		return ;
	while (a)
	{
		a->index = index;
		a = a->next;
		index++;
	}
}

void	helper_rotate(t_node **stack, t_node *curr, char c)
{
	if (curr->index <= ft_lstsize(*stack) / 2)
	{
		while ((*stack)->digit != curr->digit)
		{
			if (c == 'a')
				ra(stack, 1);
			else if (c == 'b')
				rb(stack, 1);
		}
	}
	else
	{
		while ((*stack)->digit != curr->digit)
		{
			if (c == 'a')
				rra(stack, 1);
			else if (c == 'b')
				rrb(stack, 1);
		}
	}
}

void	sort_2_3(t_node **a)
{
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->digit > (*a)->next->digit)
			sa(a, 1);
	}
	else
	{
		if ((*a)->digit > (*a)->next->digit)
			sa(a, 1);
		if ((*a)->next->digit > (*a)->next->next->digit)
			rra(a, 1);
		if ((*a)->digit > (*a)->next->digit)
			sa(a, 1);
	}
}

void	sort_4_5(t_node **a, t_node **b)
{
	int		index;
	int		size;
	t_node	*curr;

	index = 0;
	if (ft_lstsize(*a) == 4)
		size = 1;
	else
		size = 2;
	while (index < size)
	{
		curr = *a;
		get_index(*a);
		while (curr->position != index)
			curr = curr->next;
		helper_rotate(a, curr, 'a');
		pb(a, b);
		index++;
	}
	sort_2_3(a);
	while (*b)
		pa(a, b);
}
