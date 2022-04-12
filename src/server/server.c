/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 10:47:55 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/12 19:44:40 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <signal.h>
# include "../../libft/libft.h"

void	write_binary(int num, int bit_count)
{
	int		bit;

	bit = 0;
	bit_count -= 1;
	while (bit_count >= 0)
	{
		bit = num >> bit_count &1;
		bit += 48;
		write(1, &bit, 1);
		bit_count--;
	}
	write(1, "\n", 1);
}

int	set_next_bit(int num, int bit)
{
	return (num << 1 | bit);
}

void	handle_signal(int signal, siginfo_t *info, void *vp)
{
	static int				count = 8;
	static unsigned char	num = '\0';

	vp = NULL;
	if (signal == SIGUSR1)
		num = set_next_bit(num, 0);
	else if (signal == SIGUSR2)
		num = set_next_bit(num, 1);
	count--;
	if (count == 0)
	{
		ft_putnbr_fd(num, 1);
		write(1, "\n", 1);
		write(1, &num, 1);
		count = 8;
		num = '\0';
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction 	sig;
	pid_t				pid;

	pid = getpid();
	ft_putstr_fd("Process ID: ", 0);
	ft_putnbr_fd(pid, 0);
	ft_putstr_fd("\n", 0);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &handle_signal;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		sleep(1);
	return (0);
}
