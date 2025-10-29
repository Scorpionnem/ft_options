/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:59:38 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 09:37:08 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

t_option	*options_last(t_option *lst)
{
	int	count;

	count = options_size(lst);
	while (count > 1)
	{
		lst = lst->next;
		count--;
	}
	return (lst);
}
