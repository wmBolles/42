/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 06:57:22 by wabolles          #+#    #+#             */
/*   Updated: 2024/07/25 23:39:17 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				digit;
	int				position;
	int				index;
	int				c;
	struct s_node	*next;
}	t_node;

char			*ft_strjoin(char const *s1, char const *s2);
void			exit_err(void);
int				is_spaces(char c);
int				ft_atoi(char *str);
char			**ft_split(char *str);
size_t			ft_strlen(const char *s);
char			*join_args(int ac, char *av[]);
void			ft_lstadd_back(t_node **lst, t_node *new);
t_node			*ft_lstnew(int content);
int				ft_lstsize(t_node *lst);
t_node			*last_node(t_node *lst);
void			pa(t_node **a, t_node **b);
void			pb(t_node **a, t_node **b);
void			sa(t_node **a, int check);
void			sb(t_node **b, int check);
void			ss(t_node **a, t_node **b);
void			ra(t_node **a, int check);
void			rb(t_node **b, int check);
void			rr(t_node **a, t_node **b);
void			rra(t_node **a, int check);
void			rrb(t_node **b, int check);
void			rrr(t_node **a, t_node **b);
void			sort(t_node **a, t_node **b);
int				sorted(t_node *a);
void			sort_2_3(t_node **a);
void			get_index(t_node *a);
void			helper_rotate(t_node **stack, t_node *curr, char c);
void			sort_4_5(t_node **a, t_node **b);
void			set_pos(t_node **a);
void			helper_pos(t_node *stack, t_node *curr, int size, int var);

#endif