/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:36:57 by mbatty            #+#    #+#             */
/*   Updated: 2025/10/29 16:54:46 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_options_internal.h"

void	ft_bzero_opt(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n--)
	{
		*str++ = '\0';
	}
}

char	*ft_strchr_opt(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen_opt(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen_opt(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_error(char *str)
{
	write(2, str, ft_strlen_opt(str));
}

void	ft_putchar_error(char c)
{
	write(2, &c, 1);
}
