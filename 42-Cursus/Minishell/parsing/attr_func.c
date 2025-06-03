/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:03:08 by wabolles          #+#    #+#             */
/*   Updated: 2024/11/29 20:49:32 by wabolles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	__attribute__ ((constructor))	init(void)
{
	rl_catch_signals = 0;
	ft_signal();
}

void	__attribute__ ((destructor))
	_endfn(void)
{
	close_fds();
}
