/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:53:28 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 11:00:52 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

void	ft_free_opt(t_opts *options)
{
	t_option	*tmp;
	t_option	*opt;
	
	opt = options->opts;
	if (!opt)
		return ;
	tmp = opt;
	while (opt)
	{
		tmp = (opt)->next;
		free(opt);
		opt = tmp;
	}
}
