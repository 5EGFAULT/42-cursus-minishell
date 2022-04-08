/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 02:12:30 by asouinia          #+#    #+#             */
/*   Updated: 2022/04/08 02:26:19 by asouinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/builder.h"

void	builder_free_builder_redir(t_d_list *redir)
{
	t_d_list	*tmp;
	t_redir		*redir_tmp;

	tmp = redir;
	while (tmp)
	{
		redir_tmp = tmp->content;
		if (redir_tmp->file)
			free(redir_tmp->file);
		free(redir_tmp);
		tmp = tmp->next;
	}
	if (redir)
		free(redir);
}

void	builder_free_builder_pipline(t_d_list *build)
{
	t_d_list	*tmp;
	int			i;

	tmp = build;
	while (tmp)
	{
		i = -1;
		if (((t_builder *)tmp->content)->type == B_CMD)
		{
			while (((t_builder *)tmp->content)->cmd->args[++i])
				free(((t_builder *)tmp->content)->cmd->args[i]);
			free(((t_builder *)tmp->content)->cmd->args);
			//if (((t_builder *)tmp->content)->cmd->pipefd)
			//	free(((t_builder *)tmp->content)->cmd->pipefd);
			builder_free_builder_redir(((t_builder *)tmp->content)->cmd->redir_in);
			builder_free_builder_redir(((t_builder *)tmp->content)->cmd->redir_out);
			free(((t_builder *)tmp->content)->cmd);
		}
		else
			builder_free_builder_op((t_builder *)tmp->content);
			free(((t_builder *)tmp->content));
		tmp = tmp->next;
	}
	if (build)
		free(build);
}

void	builder_free_builder_op(t_builder *build)
{
	builder_free_builder(build->left);
	builder_free_builder(build->right);
	free(build);
}

void	builder_free_builder(t_d_list *build)
{
	t_builder	*b;

	if (!build)
		return ;
	b = (t_builder *)build->content;
	if (b->type == B_CMD)
		builder_free_builder_pipline(build);
	else if (b->type == B_OR || b->type == B_AND)
	{
		builder_free_builder_op((t_builder *)build->content);
		free(build);
	}
}
