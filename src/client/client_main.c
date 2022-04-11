#include "client.h"

unsigned int	set_next_bit(unsigned int num, int bit)
{
	return (num << 1 | bit);
}

int	get_bit_char(unsigned int c, int shift)
{
	return (c >> shift &1);
}

int	main(int argc, char **argv)
{
	pid_t			pid;
	unsigned int	new_char;
	int				bit;
	int				i;
	int				shift;

	if (argc != 3)
		exit_with_error("please start the client with: pid_t and \"string to be sent\" as arguments\n");
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		shift = 8;
		new_char = 0;
		while (shift >= 0)
		{
			bit = get_bit_char(argv[2][i], shift);
			new_char = set_next_bit(new_char, bit);
			shift--;
		}
		write(1, &new_char, 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
	printf("sigusr1 %d sigusr2 %d\n", SIGUSR1, SIGUSR2);
	return (0);
}
