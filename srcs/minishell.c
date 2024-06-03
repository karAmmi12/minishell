/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:10:25 by kammi             #+#    #+#             */
/*   Updated: 2024/06/03 11:36:30 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_data	*initialize_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
	{
		printf("Error: malloc failed\n");
		exit(1);
	}
	data->env = NULL;
	data->env_array = NULL;
	data->prompt = NULL;
	data->tokens = NULL;
	data->first_token = NULL;
	data->token_count = 0;
	data->ast = NULL;
	data->first_redir_out = NULL;
	data->token_count = 0;
	data->here_doc_fd = 0;
	data->exit_status = 0;
	return (data);
}

t_data	*initialize_program(int ac, char **av, char **env)
{
	t_data	*data;
	int		i;

	i = 0;
	if (ac != 1)
	{
		printf("Error: too many arguments\n");
		exit(1);
	}
	(void)av;
	signals_handler();
	data = initialize_data();
	data->env = init_env(data, env, i);
	if (data->env == NULL)
	{
		printf("Error: malloc failed\n");
		exit(1);
	}
	return (data);
}

void	run_program(t_data *data)
{
	while (1)
	{
		data->prompt = prompt(data);
		data->tokens = tokenizer(data->prompt, data, true);
		handle_here_doc(data, &data->tokens);
		data->first_token = data->tokens;
		data->ast = parse_tokens(&data->tokens);
		adjust_ast(data->ast);
		adjust_ast_file(data->ast);
		executor(data, data->ast);
		ft_free_data(data);
		delete_tmp_files();
	}
}
