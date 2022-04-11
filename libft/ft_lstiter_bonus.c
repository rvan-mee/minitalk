/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:12:06 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 13:12:08 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next;
	void	*content;

	if (!lst)
		return ;
	next = lst->next;
	content = lst->content;
	while (next)
	{
		f(content);
		content = next->content;
		next = next->next;
	}
	f(content);
}
