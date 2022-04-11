
#include "server.h"

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("Process ID: ", 0);
	ft_putnbr_fd(pid, 0);
	ft_putstr_fd("\n", 0);
	// printf("sigusr1 %d sigusr2 %d\n", SIGUSR1, SIGUSR2);
	while (1)
	{

	}
	return (0);
}
