/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:13:21 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 09:37:09 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

void	options_add_back(t_option **lst, t_option *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
		options_last(*lst)->next = new;
	}
	else
		*lst = new;
}
