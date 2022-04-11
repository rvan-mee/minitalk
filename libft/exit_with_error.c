/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_with_error.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:38:54 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/11 17:42:24 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_with_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}
