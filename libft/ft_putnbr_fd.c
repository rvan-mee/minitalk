/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:12:36 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 13:12:37 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = n;
	if (i < 0)
	{
		i *= -1;
		write(fd, "-", 1);
	}
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	i %= 10;
	i += 48;
	write(fd, &i, 1);
}
