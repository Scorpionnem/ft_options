/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:14:15 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 09:35:14 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTIONS_H
# define FT_OPTIONS_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_option
{
	char	opt;
	bool	set;
	char	*arg;

	struct s_option	*next;
}	t_option;

/*
	Parses options

	@return pointer to the first node of a list of options or NULL on error

	@param bool_opts list of boolean options
	@param arg_opts list of options that need an argument
	@param args	av given to main
*/
t_option	*ft_getopt(const char *bool_opts, const char *arg_opts, char **args);

/*
	Finds an option in the list of options

	@param opt option's id to find
	@param options pointer to the list of options

	@return pointer to the node containing the option or NULL if not found or on error
*/
t_option	*ft_find_opt(const char opt, t_option *options);

void	ft_free_opt(t_option *options);

#endif
