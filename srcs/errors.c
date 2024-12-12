/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:16 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/12 08:54:01 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_correct_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd
			("Error\nto use: ./pipex <infile> <cmd1><cmd2> <outfile>\n", 1);
		exit(1);
	}
}

void	ft_command_error(t_data *data, int cmd_nb)
{
	if (cmd_nb == 1)
	{
		if (data->cmds[0][0] == NULL)
			ft_putstr_fd(" : command not found\n", 2);
		else
		{
			ft_putstr_fd(data->cmds[0][0], 2);
			ft_putstr_fd(": command not found\n", 2);
		}
	}
	else if (cmd_nb == 2)
	{
		if (data->cmds[1][0] == NULL)
			ft_putstr_fd(" : command not found\n", 2);
		else
		{
			ft_putstr_fd(data->cmds[1][0], 2);
			ft_putstr_fd(": command not found\n", 2);
		}
		data->error = 127;
	}
}
