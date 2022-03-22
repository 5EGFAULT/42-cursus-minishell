/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:30:59 by mbalagui          #+#    #+#             */
/*   Updated: 2022/03/22 19:26:02 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

void	readinputs(char **read);
size_t	ft_strlen(const char *c);
int		skiplfspace(char *str, int defaultval);
int		skiprtspace(char *str);
char	**split_cmds(char *line);
int		quotescheckers(char *str, int end);
int		*get_pipe_idxs(char *line);
char	*ft_strdup_v2(char *s1, int idx_start, int idx_end);
int		emptypipes(char *str);
void	ft_echo(char *str);
char	**ft_split(char const *s, char c);
int		count_max_multiple_pipes(char *str);
int		check_end_start_pipes(char *line);

#endif