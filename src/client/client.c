/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 10:47:49 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/05/18 17:38:10 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../../libft/libft.h"

int	g_breakout = 0;

// Shifts c by shift amount and then returns the bit
// at that position.
int	get_bit_of_byte(unsigned int c, int shift)
{
	return (c >> shift & 1);
}

// Used to set the global breakout value
// to 1, indicating a recieved signal.
void	got_signal(int sig)
{
	if (sig == SIGUSR2)
		g_breakout = 1;
}

// Splits the given byte using get_bit_of_byte()
// in a while loop, sending 1 bit per time to the given PID.
// After sending a bit it will wait for confirmation. 
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
		if (return_check != 0)
			exit_with_error("Please use the right PID\n");
		shift--;
		signal(SIGUSR2, got_signal);
		while (1)
		{
			if (g_breakout == 1)
				break ;
		}
		g_breakout = 0;
	}
}

// Takes a PID and a string as input.
// Tries to send each byte of the string over
// using send_byte.
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
