/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:24 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/06 18:54:25 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec_cmd1(t_data *data, char **envp)
{		
	if (dup2(data->pipe_fds[1], STDOUT_FILENO) == -1)
		perror("dup2");
	ft_close(data->pipe_fds[0]);
	ft_close(data->pipe_fds[1]);
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
		perror("dup2");
	ft_close(data->infile_fd);
	ft_close(data->outfile_fd);
	if (execve(data->cmd1, data->cmds[0],
			envp) == -1)
	{
		ft_putstr_fd("Error execve\n", 2);
		exit(1);
	}
}

static void	ft_exec_cmd2(t_data *data, char **envp)
{
	if (dup2(data->pipe_fds[0], STDIN_FILENO) == -1)
		perror("dup2");
	ft_close(data->pipe_fds[0]);
	ft_close(data->pipe_fds[1]);
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
		perror("dup2");
	ft_close(data->infile_fd);
	ft_close(data->outfile_fd);
	if (execve(data->cmd2, data->cmds[1],
			envp) == -1)
	{
		ft_putstr_fd("Error execve\n", 2);
		exit(1);
	}
}

void	ft_child1_exec(t_data *data, char **envp)
{
	if (data->pid1 == -1)
		exit(1);
	else if (data->pid1 == 0)
		ft_exec_cmd1(data, envp);
}

void	ft_child2_exec(t_data *data, char **envp)
{
	if (data->pid2 == -1)
		exit(1);
	else if (data->pid2 == 0)
		ft_exec_cmd2(data, envp);
}
