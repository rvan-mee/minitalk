/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 10:47:55 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/13 20:31:45 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../../libft/libft.h"

// Will shift the input num to the left one time
// and set the given bit on the new position.
int	set_next_bit(int num, int bit)
{
	return (num << 1 | bit);
}

// Converts the signal into a bit which will be set inside c.
// Once a bit has been set a signal
// will be sent back to the proccess that sent it.
// After 8 bits have been set it will print c.
void	handle_signal(int signal, siginfo_t *info, void *vp)
{
	static int				count = 8;
	static unsigned char	c = '\0';

	vp = NULL;
	if (signal == SIGUSR1)
		c = set_next_bit(c, 0);
	else if (signal == SIGUSR2)
		c = set_next_bit(c, 1);
	count--;
	if (count == 0)
	{
		write(1, &c, 1);
		count = 8;
		c = '\0';
	}
	kill(info->si_pid, SIGUSR2);
}

// Prints out its own proccess ID and then waits for a signal.
// If a signal (SIGUSR1 or SIGUSR2) is recieved handle_signal
// is called.
int	main(void)
{
	struct sigaction	sig;
	pid_t				pid;

	pid = getpid();
	ft_putstr_fd("Process ID: ", 0);
	ft_putnbr_fd(pid, 0);
	ft_putstr_fd("\n", 0);
	sig.sa_flags = SA_SIGINFO | SA_NODEFER;
	sig.sa_sigaction = &handle_signal;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		sleep(1);
	return (0);
}
