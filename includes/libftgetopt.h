/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftgetopt.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:14:15 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 14:52:02 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTGETOPT_H
# define LIBFTGETOPT_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/*
	Option structure, contains wether its set and it's argument
*/
typedef struct s_option
{
	char	opt;
	bool	set;
	char	*arg;

	struct s_option	*next;
}	t_option;

/*
	Linked list of arguments
*/
typedef struct s_arg
{
	char		*arg;

	struct s_arg	*next;
}	t_arg;

/*
	Structure containing everything about ft_getopt, options and remaining args
*/
typedef struct	s_opts
{
	t_option	*opts;
	/*
		Remaining args from ft_getopt
	*/
	t_arg		*args;

	const char	*bool_opts;
	const char	*arg_opts;
}	t_opts;

/*
	Parses options

	@return pointer to the first node of a list of options or NULL on error

	@param bool_opts list of boolean options
	@param arg_opts list of options that need an argument
	@param args	av given to main
*/
t_opts	*ft_getopt(const char *bool_opts, const char *arg_opts, char **args);

/*
	Finds an option in the list of options

	@param opt option's id to find
	@param options pointer to the list of options

	@return pointer to the node containing the option or NULL if not found or on error
*/
t_option	*ft_find_opt(const char opt, t_opts *options);

/*
	Frees the whole t_opt structure

	@param options options structure to free
*/
void	ft_free_opt(t_opts *options);

#endif
