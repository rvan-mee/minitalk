/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:12:15 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 13:12:16 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*struct1;

	struct1 = malloc(sizeof(t_list));
	if (struct1 == 0)
		return (0);
	struct1->content = content;
	struct1->next = 0;
	return (struct1);
}
