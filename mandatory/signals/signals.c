/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:28:44 by asouinia          #+#    #+#             */
/*   Updated: 2022/04/16 23:53:58 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/signals.h"

void	signal_init(int sig)
{
	(void)sig;
	//printf("{{ sig init : %d}}\n", sig);
	//printf("asdasd\n");
	//printf("\n");
	//rl
	//if (g_global.current_pid == getpid())
	//{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		////printf("%d %d \n",getpid(), g_global.current_pid);
		g_global.prev_exit_code = 130;
		g_global.exit_code = 130;
	//}
	//init_minishell();
}


void	signal_quit(int sig)
{
	printf("{{ sig quit : %d}}\n", sig);
}