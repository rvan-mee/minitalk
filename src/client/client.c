/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 10:47:49 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/12 19:43:52 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../../libft/libft.h"

int	g_breakout = 0;

int	get_bit_of_byte(unsigned int c, int shift)
{
	return (c >> shift & 1);
}

void	got_signal(int sig)
{
	if (sig == SIGUSR2)
		g_breakout = 1;
}

void	send_byte(char byte, int pid)
{
	int	shift;
	int	return_check;
	int	bit;

	shift = 7;
	while (shift >= 0)
	{
		return_check = 1;
		bit = get_bit_of_byte(byte, shift);
		if (bit == 0)
			return_check = kill(pid, SIGUSR1);
		else
			return_check = kill(pid, SIGUSR2);
		shift--;
		signal(SIGUSR2, got_signal);
		while (1)
		{
			if (g_breakout == 1)
				break;
		}
		g_breakout = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t			pid;
	int				i;

	if (argc != 3)
		exit_with_error("./client [pid of server] [string]\n");
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		send_byte(argv[2][i], pid);
		i++;
	}
	send_byte('\n', pid);
	return (0);
}
