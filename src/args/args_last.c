/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:59:38 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 09:49:09 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

t_arg	*args_last(t_arg *lst)
{
	int	count;

	count = args_size(lst);
	while (count > 1)
	{
		lst = lst->next;
		count--;
	}
	return (lst);
}
