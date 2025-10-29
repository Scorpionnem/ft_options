/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:53:28 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 09:37:11 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

void	ft_free_opt(t_option *options)
{
	t_option	*tmp;
	
	if (!options)
		return ;
	tmp = options;
	while (options)
	{
		tmp = (options)->next;
		free(options);
		options = tmp;
	}
}
