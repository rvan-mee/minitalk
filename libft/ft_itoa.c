/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:11:54 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 13:11:56 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recursive(long n, int *i, char *str)
{
	if (n > 9)
		recursive(n / 10, i, str);
	n %= 10;
	str[*i] = n + 48;
	*i += 1;
}

char	*ft_itoa(int n)
{
	char		*str;
	int			neg;
	int			i;
	long		j;

	i = 0;
	neg = 0;
	j = n;
	if (j < 0)
	{
		j *= -1;
		neg++;
		i++;
	}
	str = malloc(sizeof(char) * intlength(j) + neg + 1);
	if (str == 0)
		return (0);
	if (neg == 1)
		str[0] = '-';
	recursive(j, &i, str);
	str[i] = '\0';
	return (str);
}
