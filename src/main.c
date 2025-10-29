/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:14:20 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 11:06:34 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_options_internal.h"

# include <stdio.h>

t_option	*ft_find_opt(const char opt, t_opts *opts)
{
	t_option	*options;

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
			return (0);
		options_add_back(opts, new);
	}
	i = -1;
	while (arg_opts[++i])
	{
		new = options_new(arg_opts[i]);
		if (!new)
			return (0);
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
			return (0);
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
	printf("No arg given\n");
	return (0);
}

t_opts	*ft_getopt(const char *bool_opts, const char *arg_opts, char **av)
{
	(void)av;
	
	t_opts		*opts;
	t_option	*options;
	t_arg		*args;
	t_arg		*first_arg;

	opts = malloc(sizeof(t_opts));
	options = NULL;
	args = NULL;
	if (!ft_create_opt(&options, bool_opts, arg_opts))
		return (NULL);
	if (!ft_get_args(&args, av))
		return (NULL);

	opts->args = args;
	opts->opts = options;
	first_arg = args;
	while (first_arg)
	{
		if (first_arg->arg[0] == '-' && first_arg->arg[1])
		{
			if (is_arg_opt(first_arg))
			{
				int i = 1;
				while (first_arg->arg[i])
				{
						if (ft_strchr(bool_opts, first_arg->arg[i]))
							ft_fill_bool_opt(opts, first_arg->arg[i]);
						else if (ft_strchr(arg_opts, first_arg->arg[i]))
							ft_fill_arg_opt(opts, first_arg->arg[i], first_arg);	
						else
						{
							printf("Unknown option %c\n", first_arg->arg[i]);
							return (NULL);
						}
					i++;
				}
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

	t_option *ip_opt = ft_find_opt('i', opts);
	if (ip_opt)
		printf("IP set: %d with string %s\n", ip_opt->set, ip_opt->arg);

	t_option *port_opt = ft_find_opt('p', opts);
	if (port_opt)
		printf("Port set: %d with string %s\n", port_opt->set, port_opt->arg);

	t_option *skibidi_opt = ft_find_opt('s', opts);
	if (skibidi_opt)
		printf("Skibidi set: %d\n", skibidi_opt->set);

	ft_free_opt(opts);
}
