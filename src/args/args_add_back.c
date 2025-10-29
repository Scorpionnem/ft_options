/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:13:21 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 09:48:53 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

void	args_add_back(t_arg **lst, t_arg *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
		args_last(*lst)->next = new;
	}
	else
		*lst = new;
}
