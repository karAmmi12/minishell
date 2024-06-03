/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:41:23 by apintus           #+#    #+#             */
/*   Updated: 2024/05/29 14:25:18 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/******************************VISUAL********************************/

/* const char	*get_token_type_name(t_token_type type)
{
	const char	*token_type_names[12];

	token_type_names[0] = "WORD";
	token_type_names[1] = "PIPE";
	token_type_names[2] = "REDIRECT_IN";
	token_type_names[3] = "REDIRECT_OUT";
	token_type_names[4] = "REDIRECT_APPEND";
	token_type_names[5] = "REDIRECT_HEREDOC";
	token_type_names[6] = "TOKEN_ENV_VAR";
	token_type_names[7] = "CMD";
	token_type_names[8] = "ARG";
	token_type_names[9] = "INFILE";
	token_type_names[10] = "OUTFILE";
	token_type_names[11] = "LIMITER";
	if (type >= 0 && type < 12)
		return (token_type_names[type]);
	return ("UNKNOWN");
}

void	display_tokens(t_token *tokens)
{
	t_token	*token;

	token = tokens;
	while (token)
	{
		printf("Token: \033[0;36m %-20s \033[0m |\t \
			Type: \033[0;35m %-18s \033[0m \n",
			token->value, get_token_type_name(token->type));
		printf("--------------------------------------------------\n");
		token = token->next;
	}
}

void print_ast(t_ast *node, int depth)
{
	if (node == NULL)
		return;

	// Print the current node with indentation
	for (int i = 0; i < depth; i++)
		printf("  ");

	// Print the type of the node
	switch(node->type) {
		case WORD:
			printf("WORD: ");
			for (int i = 0; node->args[i] != NULL; i++)
				printf("%s ", node->args[i]);
			printf("\n");
			break;
		case PIPE:
			printf("PIPE: |\n");
			break;
		case REDIR_OUT:
			printf("REDIR_OUT: >\n");
			break;
		case REDIR_IN:
			printf("REDIR_IN: <\n");
			break;
		case REDIR_APPEND:
			printf("REDIR_APPEND: >>\n");
			break;
		case REDIR_HEREDOC:
			printf("REDIR_HEREDOC: <<\n");
			break;
		case CMD:
			printf("CMD: ");
			for (int i = 0; node->args[i] != NULL; i++)
				printf("%s ", node->args[i]);
			printf("\n");
			break;
		case ARG:
			printf("ARG: ");
			for (int i = 0; node->args[i] != NULL; i++)
				printf("%s ", node->args[i]);
			printf("\n");
			break;
		case INFILE:
			printf("INFILE: ");
			for (int i = 0; node->args[i] != NULL; i++)
				printf("%s ", node->args[i]);
			printf("\n");
			break;
		case OUTFILE:
			printf("OUTFILE: ");
			for (int i = 0; node->args[i] != NULL; i++)
				printf("%s ", node->args[i]);
			printf("\n");
			break;
		case LIMITER:
			printf("LIMITER: ");
			for (int i = 0; node->args[i] != NULL; i++)
				printf("%s ", node->args[i]);
			printf("\n");
		default:
			printf("UNKNOWN TYPE\n");
			break;
	}

	if (node->left != NULL) {
		printf("%*s├─ Left: ", depth * 2, "");
		print_ast(node->left, depth + 1);
	}
	if (node->right != NULL) {
		printf("%*s└─ Right: ", depth * 2, "");
		print_ast(node->right, depth + 1);
	}
} */
