/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:14:20 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 13:55:28 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

# include <stdio.h>

t_option	*ft_find_opt(const char opt, t_opts *opts)
{
	t_option	*options;

	if (!opts)
		return (NULL);

	options = opts->opts;
	while (options)
	{
		if (options->opt == opt)
			return (options);
		options = options->next;
	}
	return (NULL);
}

static int	ft_create_opt(t_option **opts, const char *bool_opts, const char *arg_opts)
{
	int	i;
	t_option	*new;

	i = -1;
	while (bool_opts[++i])
	{
		new = options_new(bool_opts[i]);
		if (!new)
		{
			printf("ft_getopt: alloc error\n");
			return (0);
		}
		options_add_back(opts, new);
	}
	i = -1;
	while (arg_opts[++i])
	{
		new = options_new(arg_opts[i]);
		if (!new)
		{
			printf("ft_getopt: alloc error\n");
			return (0);
		}
		options_add_back(opts, new);
	}
	return (1);
}

static int	ft_get_args(t_arg **args, char **av)
{
	int	i;
	t_arg	*new;

	i = 0;
	while (av[++i])
	{
		new = args_new(av[i]);
		if (!new)
		{
			printf("ft_getopt: alloc error\n");
			return (0);
		}
		args_add_back(args, new);
	}
	return (1);
}

static bool	is_arg_opt(t_arg *args)
{
	if (args->arg[0] == '-' && args->arg[1])
		return (true);
	return (false);
}

static int	ft_fill_bool_opt(t_opts *opts, char c_opt)
{
	t_option	*opt;

	opt = ft_find_opt(c_opt, opts);
	if (!opt)
		return (0);
	opt->set = true;
	return (1);
}

static int	ft_fill_arg_opt(t_opts *opts, char c_opt, t_arg *args)
{
	t_option	*opt;
	t_arg	*prev;

	opt = ft_find_opt(c_opt, opts);
	if (!opt)
		return (0);
	opt->set = true;
	prev = NULL;
	while (args)
	{
		if (!is_arg_opt(args))
		{
			opt->arg = args->arg;
			if (prev)
				prev->next = args->next;
			free(args);
			return (1);
		}
		prev = args;
		args = args->next;
	}
	printf("ft_getopt: no arg given for flag '%c'\n", c_opt);
	return (0);
}

int	ft_parse_opt(t_opts *opts, t_arg *first_arg, char c_opt)
{
	if (ft_strchr(opts->bool_opts, c_opt))
	{
		if (!ft_fill_bool_opt(opts, c_opt))
			return (0);
	}
	else if (ft_strchr(opts->arg_opts, c_opt))
	{
		if (!ft_fill_arg_opt(opts, c_opt, first_arg))
			return (0);
	}
	else
	{
		printf("ft_getopt: unknown option: `%c`\n", c_opt);
		return (1);
	}
	return (1);
}

void	remove_arg(t_arg **args, t_arg *target)
{
	t_arg	*prev;
	t_arg	*start;

	start = *args;
	prev = NULL;
	while (start)
	{
		if (start == target)
		{
			if (prev)
			{
				prev->next = start->next;
				free(target);
				return ;
			}
			else
			{
				*args = start->next;
				free(target);
				return ;
			}
		}
		prev = start;
		start = start->next;
	}
}

t_opts	*ft_getopt(const char *bool_opts, const char *arg_opts, char **av)
{
	t_opts		*opts;
	t_arg		*first_arg;

	opts = malloc(sizeof(t_opts));
	if (!opts)
	{
		printf("ft_getopt: alloc error\n");
		return (NULL);
	}
	ft_bzero(opts, sizeof(t_opts));
	opts->arg_opts = arg_opts;
	opts->bool_opts = bool_opts;
	if (!ft_create_opt(&opts->opts, bool_opts, arg_opts))
	{
		ft_free_opt(opts);
		return (NULL);
	}
	if (!ft_get_args(&opts->args, av))
	{
		ft_free_opt(opts);
		return (NULL);
	}

	first_arg = opts->args;
	while (first_arg)
	{
		if (first_arg->arg[0] == '-' && first_arg->arg[1])
		{
			if (is_arg_opt(first_arg))
			{
				int i = 1;
				while (first_arg->arg[i])
				{
					t_option	*tmp = ft_find_opt(first_arg->arg[i], opts);
					if (tmp && tmp->set)
					{
						tmp->arg = NULL;
						tmp->set = false;
					}
					if (!ft_parse_opt(opts, first_arg, first_arg->arg[i]))
					{
						ft_free_opt(opts);
						return (NULL);
					}
					i++;
				}
				t_arg	*tmp = first_arg;
				first_arg = first_arg->next;
				remove_arg(&opts->args, tmp);
				continue ;
			}
		}
		first_arg = first_arg->next;
	}
	return (opts);
}

int	main(int ac, char **av)
{
	(void)ac;
	t_opts *opts = ft_getopt("s", "pi", av);
	if (!opts)
		return (1);
		
	t_option *ip_opt = ft_find_opt('i', opts);
	if (ip_opt)
		printf("IP: %d, %s\n", ip_opt->set, ip_opt->arg);

	t_option *port_opt = ft_find_opt('p', opts);
	if (port_opt)
		printf("Port: %d, %s\n", port_opt->set, port_opt->arg);

	t_option *skibidi_opt = ft_find_opt('s', opts);
	if (skibidi_opt)
		printf("Skibidi: %d\n", skibidi_opt->set);

	t_arg	*tmp = opts->args;
	while (tmp)
	{
		printf("Remaining arg %s\n", tmp->arg);
		tmp = tmp->next;
	}

	ft_free_opt(opts);
}
