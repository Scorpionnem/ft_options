/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:03:14 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 16:54:38 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

t_arg	*args_new(char *arg)
{
	t_arg		*new_opt;

	new_opt = malloc(sizeof(t_arg));
	if (!new_opt)
		return (NULL);
	ft_bzero_opt(new_opt, sizeof(t_arg));
	new_opt->arg = arg;
	return (new_opt);
}
