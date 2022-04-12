/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:11:10 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/12 14:19:40 by rvan-mee      ########   odam.nl         */
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
	if (*nptr != '\0')
		exit_with_error("Please use a correct PID\n");
	return ((int) c * value);
}
