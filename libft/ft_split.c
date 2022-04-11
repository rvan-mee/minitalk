/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:12:41 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 13:56:17 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countstr(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && i == 0)
			j++;
		if ((s[i] == c && s[i + 1] != c) && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

int	nextchar(char *str, char c, int i)
{
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char	*strchop(char *s, char c, int *k)
{
	char	*str;
	int		len;

	while (s[*k] == c)
		(*k)++;
	len = nextchar(s, c, *k) - *k;
	str = ft_substr(s, *k, len);
	if (str == 0)
		return (0);
	*k += len;
	return (str);
}

void	freeall(char **str, int i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		stringcount;
	char	**str;
	int		i;
	int		k;

	if (!(s))
		return (0);
	i = 0;
	k = 0;
	stringcount = countstr((char *)s, c);
	str = malloc((stringcount + 1) * sizeof(char *));
	if (str == 0)
		return (0);
	while (i != stringcount)
	{
		str[i] = strchop((char *)s, c, &k);
		if (str[i] == 0)
		{
			freeall(str, i);
			return (0);
		}
		i++;
	}
	str[i] = 0;
	return (str);
}
