/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:16 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/06 18:54:19 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_correct_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error\nto use: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 1);
		exit(1);
	}
}

void	ft_command_error(t_data *data, int error)
{
	if (error == 1)
	{
		ft_putstr_fd("command not found:", 2);
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(data->cmds[1][0], 2);
		ft_putstr_fd("\n", 2);
		ft_free_str(data->paths);
		ft_free_cmds(data->cmds);
		ft_close(data->infile_fd);
		ft_close(data->outfile_fd);
		ft_close(data->pipe_fds[0]);
		ft_close(data->pipe_fds[1]);
	}
	else if (error == 2)
	{
		ft_putstr_fd("command not found:", 2);
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(data->cmds[1][0], 2);
		ft_putstr_fd("\n", 2);
		ft_free_str(data->paths);
		ft_free_cmds(data->cmds);
		ft_close(data->infile_fd);
		ft_close(data->outfile_fd);
		ft_close(data->pipe_fds[0]);
		ft_close(data->pipe_fds[1]);
	}
	exit(1);
}
