/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:57:57 by stissera          #+#    #+#             */
/*   Updated: 2022/04/01 10:47:31 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	main(int argc, char **argv)
{
	char				*pid;
	int					server_pid;
	struct sigaction	sa_client;

	sa_client.sa_sigaction = &sigf;
	sigaction(SIGINT, &sa_client, NULL);
	sigaction(SIGUSR1, &sa_client, NULL);
	sigaction(SIGUSR2, &sa_client, NULL);
	if (argc < 2)
		kill(getpid(), SIGINT);
	pid = ft_itoa(getpid());
	server_pid = ft_atoi(argv[1]);
	write (1, "PID du client: ", 16);
	write (1, pid, ft_strlen(pid));
	write (1, "\n", 1);
	while (*argv[2] != '\0')
	{
		send_msg(argv[2], server_pid);
		argv[2]++;
	}
	send_null(server_pid);
	sleep(1);
	return (0);
}

void	send_msg(char *set, int server_pid)
{
	unsigned char		*bit;
	int					count;

	count = 0;
	bit = convert_bit((unsigned char *)set);
	while (count < 8)
	{
		if (bit[count] == '1')
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(30);
		count++;
	}
	free(bit);
}

void	send_null(int server_pid)
{
	int	count;

	count = 0;
	while (count < 8)
	{
		kill(server_pid, SIGUSR1);
		usleep(30);
		count++;
	}
}

void	sigf(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGINT)
	{
		write (1, "Argument error! Porgram abort.\n", 32);
		write (1, "\nExemple to use: ./client [PID_SERVER] [MESSAGE]\n", 50);
		exit (0);
	}
	if (sig == SIGUSR2)
		write(1, "Message sent...\n", 20);
	siginfo = NULL;
	context = NULL;
}

unsigned char	*convert_bit(unsigned char *set)
{
	int				i;
	int				car;
	unsigned char	*ret;

	ret = (unsigned char *)malloc(sizeof(unsigned char) * 9);
	if (!ret)
		return (0);
	ret[8] = '\0';
	i = 7;
	car = (unsigned int)set[0];
	while (car != 0)
	{
		if (car % 2 == 0)
			ret[i] = '0';
		else
			ret [i] = '1';
		car /= 2;
		i--;
	}
	while (i >= 0)
	{
		ret[i] = '0';
		i--;
	}
	return (ret);
}
