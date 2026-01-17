/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:49:38 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/26 00:06:35 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	helper_pos(t_node *stack, t_node *curr, int size, int var)
{
	int		index;

	index = 0;
	while (index <= size)
	{
		var = 2147483647;
		curr = stack;
		while (curr)
		{
			if (curr->digit <= var && curr->index == 0)
				var = curr->digit;
			curr = curr->next;
		}
		curr = stack;
		while (curr)
		{
			if (curr->digit == var)
			{
				curr->index = 1;
				curr->position = index;
			}
			curr = curr->next;
		}
		index++;
	}
}

void	set_pos(t_node **a)
{
	t_node	*curr;
	t_node	*curr2;

	curr = *a;
	while (curr)
	{
		curr->position = 0;
		curr2 = *a;
		while (curr2)
		{
			if (curr->digit > curr2->digit)
				curr->position++;
			curr2 = curr2->next;
		}
		curr = curr->next;
	}
}

void	sort_all_helper(t_node **a, t_node **b)
{
	int		size;
	int		index;
	t_node	*curr;

	set_pos(b);
	size = ft_lstsize(*b);
	index = size - 1;
	while (index >= 0)
	{
		size = ft_lstsize(*b);
		get_index(*b);
		curr = *b;
		while (curr->position != index)
			curr = curr->next;
		helper_rotate(b, curr, 'b');
		pa(a, b);
		index--;
	}
}

void	sort_all(t_node **a, t_node **b, int size)
{
	int		index;
	int		c;

	index = 0;
	if (size <= 100)
		c = 16;
	else
		c = 34;
	while (*a)
	{
		if ((*a)->position <= index)
		{
			pb(a, b);
			index++;
		}
		else if ((*a)->position <= c + index)
		{
			pb(a, b);
			rb(b, 1);
			index++;
		}
		else
			ra(a, 1);
	}
	sort_all_helper(a, b);
}

void	sort(t_node **a, t_node **b)
{
	t_node		*curr;
	int			size;

	size = ft_lstsize(*a);
	curr = *a;
	set_pos(a);
	if (sorted(*a))
		return ;
	if (size < 2)
		return ;
	else if (size == 2 || size == 3)
		sort_2_3(a);
	else if (size == 4 || size == 5)
		sort_4_5(a, b);
	else
		sort_all(a, b, size);
}
