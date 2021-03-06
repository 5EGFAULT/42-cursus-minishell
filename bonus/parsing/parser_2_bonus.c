/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:41:54 by asouinia          #+#    #+#             */
/*   Updated: 2022/04/23 23:39:46 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/parser_bonus.h"	

void	parser_syntax_error(char *token_value)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(token_value, 2);
	ft_putstr_fd("'\n", 2);
	g_global.exit_code = EXIT_SYNTAX_ERROR;
}

int	is_redir(t_token *token)
{
	if (token->type == TOKEN_RIN)
		return (1);
	else if (token->type == TOKEN_DRIN)
		return (1);
	else if (token->type == TOKEN_ROUT)
		return (1);
	else if (token->type == TOKEN_DROUT)
		return (1);
	else
		return (0);
}

int	is_op(t_token *token)
{
	if (token->type == TOKEN_AND)
		return (1);
	else if (token->type == TOKEN_OR)
		return (1);
	else
		return (0);
}

t_ast	*parser_parse_paren(t_parser *parser)
{
	t_ast	*ast;

	if (!parser_parser_advance(parser, TOKEN_LPAREN))
		return (NULL);
	ast = parser_parse(parser);
	if (ast == NULL)
		return (NULL);
	if (!parser_parser_advance(parser, TOKEN_RPAREN))
		return (free_tree(ast), NULL);
	if (parser->token->type == TOKEN_ID)
		return (free_tree(ast), \
		parser_syntax_error(parser->token->value), NULL);
	return (ast);
}

t_ast	*parser_parse_id(t_parser *parser)
{
	t_ast	*ast;
	t_token	*token;

	token = parser->token;
	if (!parser_parser_advance(parser, TOKEN_ID))
		return (NULL);
	ast = ast_init_ast(AST_ID);
	ast->children = expand_word(token->value);
	ast->value = ft_strdup(token->value);
	return (ast);
}
