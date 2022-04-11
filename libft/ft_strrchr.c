/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:13:08 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 13:13:09 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	a;

	a = c;
	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == a)
			j = i;
		i++;
	}
	if (s[i] == a)
		j = i;
	if (j != -1)
		return ((char *) &s[j]);
	return (0);
}
