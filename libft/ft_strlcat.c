/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:12:53 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 13:12:54 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	k = ft_strlen(src);
	j = i + k;
	if (i >= dstsize)
		return (k + dstsize);
	dst += i;
	while (*src && dstsize - 1 - i > 0)
	{
		ft_memcpy(dst, src, 1);
		dst++;
		src++;
		dstsize--;
	}
	*dst = 0;
	return (j);
}
