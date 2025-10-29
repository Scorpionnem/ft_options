/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:53:28 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 11:28:33 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

static void	options_free(t_option *opts)
{
	t_option	*tmp;
	t_option	*opt;
	
	opt = opts;
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

void	ft_free_opt(t_opts *options)
{
	if (!options)
		return ;
	if (options->opts)
		options_free(options->opts);
	if (options->args)
		args_free(options->args);
	free(options);
}
