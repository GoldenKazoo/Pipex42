/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:35 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/06 18:59:28 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_correct_args(argc);
	ft_init_data(&data, argv, envp);
	if (data.infile_fd != -1)
	{
		if (data.cmd1 != NULL)
		{
			data.pid1 = fork();
			ft_child1_exec(&data, envp);
		}
		else
			ft_command_error(data, 1);
	}
	if (data.outfile_fd != -1)
	{
		if (data.cmd2 != NULL)
		{
			data.pid2 = fork();
			ft_child2_exec(&data, envp);
		}
		else
			ft_command_error(data, 2);
	}
	ft_exit(&data);
}
