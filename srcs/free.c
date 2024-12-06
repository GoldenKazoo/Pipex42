/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:45 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/06 18:54:46 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
}

static void	ft_free_cmds(char ***cmds)
{
	ft_free_str(cmds[0]);
	ft_free_str(cmds[1]);
	free(cmds);
}

void	ft_free_data(t_data *data)
{
	printf("ALED");
	free(data->cmd1);
	free(data->cmd2);
	ft_free_str(data->paths);
	ft_free_cmds(data->cmds);
}

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_exit(t_data *data)
{
	ft_close(data->infile_fd);
	ft_close(data->outfile_fd);
	ft_close(data->pipe_fds[0]);
	ft_close(data->pipe_fds[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
	ft_free_data(data);
	exit(0);
}