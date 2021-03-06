/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:34:05 by asouinia          #+#    #+#             */
/*   Updated: 2022/04/21 05:21:35 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/lexer_bonus.h"	

/**
 * @brief return a string of the current char
 * 
 * @param c 
 * @return char* c\0
 */
char	*to_str(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

/**
 * @brief check if the character is not a reserved token 
 * 
 * @param c charachter
 * @return int *1* if reserved *0* if not
 */
int	is_reserved_token(t_lexer *lexer)
{
	if (lexer->c == '&' && lexer->cc == '&')
		return (1);
	if (ft_strchr("()<>| \t", lexer->c))
		return (1);
	return (0);
}

/**
 * @brief 
 * 
 * @param lexer 
 * @param str 
 */
void	lexer_syntax_error(char *str)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
	g_global.exit_code = EXIT_SYNTAX_ERROR;
}

/**
 * @brief  
 * 
 * @param str 
 */
void	lexer_quote_error(char *str)
{
	ft_putstr_fd("minishell: Unmatched quote `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
	g_global.exit_code = EXIT_SYNTAX_ERROR;
	free(str);
}
