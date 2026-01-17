/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:40:42 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/26 00:06:59 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node		*curr;

	if (!stack)
		return ;
	while (stack)
	{
		curr = stack;
		stack = stack->next;
		free(curr);
	}
}

void	free_splits(char **splits)
{
	int		index;

	index = 0;
	while (splits[index])
	{
		free(splits[index]);
		index++;
	}
	free(splits);
}

static int	parse_splited(char **splits, char *split, int i)
{
	int		index;

	index = 0;
	if (split[index] == '-' || split[index] == '+')
	{
		if (ft_strlen(split) == 1)
			return (0);
		index++;
	}
	while (split[index])
	{
		if (split[index] < '0' || split[index] > '9')
			return (0);
		index++;
	}
	index = 0;
	while (index < i)
	{
		if (ft_atoi(splits[index]) == ft_atoi(split))
			return (0);
		index++;
	}
	return (1);
}

char	**create_stack(t_node **a, char *join)
{
	int		index;
	char	**splits;

	index = 0;
	splits = ft_split(join);
	while (splits[index])
	{
		if (parse_splited(splits, splits[index], index))
		{
			ft_lstadd_back(a, ft_lstnew(ft_atoi(splits[index])));
			index++;
		}
		else
		{
			free_stack(*a);
			free_splits(splits);
			free(join);
			exit_err();
		}
	}
	free(join);
	return (splits);
}

int	main(int ac, char *av[])
{
	t_node		*a;
	t_node		*b;
	char		**splited;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	splited = create_stack(&a, join_args(ac, av));
	sort(&a, &b);
	free_splits(splited);
	free_stack(a);
}
