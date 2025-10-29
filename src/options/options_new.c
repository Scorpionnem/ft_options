/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:03:14 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 16:54:35 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

t_option	*options_new(const char opt)
{
	t_option		*new_opt;

	new_opt = malloc(sizeof(t_option));
	if (!new_opt)
		return (NULL);
	ft_bzero_opt(new_opt, sizeof(t_option));
	new_opt->opt = opt;
	return (new_opt);
}
