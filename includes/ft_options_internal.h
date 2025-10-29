/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:33:25 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 14:51:39 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTIONS_INTERNAL_H
# define FT_OPTIONS_INTERNAL_H

# include "libftgetopt.h"

void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

void	ft_putchar_error(char c);
void	ft_putstr_error(char *str);

t_option	*options_new(const char opt);
int			options_size(t_option *lst);
t_option	*options_last(t_option *lst);
void		options_add_back(t_option **lst, t_option *new);

void	args_add_back(t_arg **lst, t_arg *new);
void	args_free(t_arg *options);
t_arg	*args_last(t_arg *lst);
t_arg	*args_new(char *arg);
int		args_size(t_arg *lst);

#endif
