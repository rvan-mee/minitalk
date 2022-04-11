/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:11:10 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 13:11:12 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	c;
	int	value;

	c = 0;
	value = 1;
	while (*nptr != '\0' && ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			value *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		c *= 10;
		c += *nptr - 48;
		nptr++;
	}
	return ((int) c * value);
}
