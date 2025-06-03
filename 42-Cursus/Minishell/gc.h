/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:18:07 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/25 17:36:07 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}	t_garbage;

static t_garbage	**gc_list(void) __attribute__ ((unused));
void				gc_add(void *ptr);
void				*gc_malloc(size_t size);
void				gc_free_all(void);