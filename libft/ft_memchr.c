/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:12:19 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 13:12:20 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	search;
	size_t			i;

	str = (unsigned char *) s;
	search = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == search)
			return (&str[i]);
		i++;
	}
	return (0);
}
