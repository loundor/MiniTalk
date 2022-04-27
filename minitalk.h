/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:17:38 by stissera          #+#    #+#             */
/*   Updated: 2022/04/01 09:36:29 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <sys/types.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

char			*ft_itoa(int PID);
int				ft_atoi(const char *src);
int				ft_strlen(const char *src);
void			send_sig(int signum);
void			sigf(int sig, siginfo_t *siginfo, void *context);
unsigned char	*convert_bit(unsigned char *set);
void			send_null(int server_pid);
void			send_msg(char *set, int server_pid);
void			stop_srv(void);
#endif