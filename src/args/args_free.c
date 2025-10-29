/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:53:28 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 09:47:29 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

void	args_free(t_arg *options)
{
	t_arg	*tmp;
	
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
