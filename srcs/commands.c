/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:03 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/06 18:54:06 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_get_cmd1(t_data *data)
{
	if (access(data->cmds[0][0], X_OK) == 0)
		data->cmd1 = ft_strdup(data->cmds[0][0]);
	else
		data->cmd1 = ft_get_path_cmd(data->paths,
				data->cmds[0][0]);
}

static void	ft_get_cmd2(t_data *data)
{
	if (access(data->cmds[1][0], X_OK) == 0)
		data->cmd2 = ft_strdup(data->cmds[1][0]);
	else
		data->cmd2 = ft_get_path_cmd(data->paths,
				data->cmds[1][0]);
}

int	ft_get_args_cmds(t_data *data, char *cmd1, char *cmd2)
{
	char	**args_cmd1;
	char	**args_cmd2;

	data->cmds = malloc(sizeof(char **) * 3);
	if (data->cmds == NULL)
		return (1);
	args_cmd1 = ft_split(cmd1, ' ');
	if (args_cmd1 == NULL)
		return (1);
	args_cmd2 = ft_split(cmd2, ' ');
	if (args_cmd2 == NULL)
		return (1);
	data->cmds[0] = args_cmd1;
	data->cmds[1] = args_cmd2;
	data->cmds[2] = NULL;
	return (0);
}

void	ft_get_cmds(t_data *data)
{
	if(data->cmds[0][0] == NULL)
	{
		ft_command_error(data, 1);
	}
	if(data->cmds[1][0] == NULL)
	{
		ft_command_error(data, 1);
	}
	ft_get_cmd1(data);
	ft_get_cmd2(data);
}
