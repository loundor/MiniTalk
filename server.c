/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:15:36 by stissera          #+#    #+#             */
/*   Updated: 2022/04/01 09:30:11 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	main(void)
{
	char				*pid;
	struct sigaction	sa_server;

	sa_server.sa_sigaction = &sigf;
	sigaction(SIGINT, &sa_server, NULL);
	sigaction(SIGUSR1, &sa_server, NULL);
	sigaction(SIGUSR2, &sa_server, NULL);
	pid = ft_itoa(getpid());
	write (1, pid, ft_strlen(pid));
	write (1, "\n", 1);
	free(pid);
	while (1)
		pause();
	return (1);
}

void	sigf(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned char	ret;
	static int				i;

	context = NULL;
	if (sig == SIGUSR1)
		ret = ret << 1;
	if (sig == SIGUSR2)
	{
		ret = ret << 1;
		ret |= 1;
	}
	i++;
	if (i == 8)
	{
		if (ret == 0)
		{
			kill(siginfo->si_pid, SIGUSR2);
			write(1, "\n", 1);
		}
		write(1, &ret, 1);
		i = 0;
		ret = 0;
	}
	if (sig == SIGINT)
		stop_srv();
}

void	stop_srv(void)
{
	write (1, "Arret du serveur.\n", 19);
	exit (0);
}
