/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:26:58 by asouinia          #+#    #+#             */
/*   Updated: 2022/04/21 05:27:00 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_BONUS_H
# define TOKEN_BONUS_H
# include "../../../libft/libft.h"

typedef enum e_token {
	TOKEN_ID,
	TOKEN_TEXT,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_OR,
	TOKEN_AND,
	TOKEN_PIPE,
	TOKEN_RIN,
	TOKEN_ROUT,
	TOKEN_DRIN,
	TOKEN_DROUT,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_EOF
}	t_e_token;

typedef struct s_token
{
	char		*value;
	t_e_token	type;
}	t_token;

t_token	*init_token(char *value, t_e_token type);
void	free_token(void *token);
#endif
