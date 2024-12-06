/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:10 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/06 18:54:12 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_data(t_data *data, char **argv, char **envp)
{
	data->pid1 = 0;
	data->pid2 = 0;
	data->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
		perror(argv[4]);
	data->infile_fd = open(argv[1], O_RDONLY);
	if (data->infile_fd == -1)
		perror(argv[1]);
	if (pipe(data->pipe_fds) == -1)
	{
		perror("pipe");
		exit(1);
	}
	data->paths = ft_path_split(envp);
	if (ft_get_args_cmds(data, argv[2], argv[3]) == 1)
		exit(1);
	ft_get_cmds(data);
}
