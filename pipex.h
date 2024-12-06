/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:24 by zchagar           #+#    #+#             */
/*   Updated: 2024/12/06 18:54:25 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	**paths;
	char	***cmds;
	char	*cmd1;
	char	*cmd2;
	int		infile_fd;
	int		outfile_fd;
	int		pid1;
	int		pid2;
	int		pipe_fds[2];
}	t_data;

void	ft_correct_args(int argc);
void	ft_command_error(t_data *data, int error);
void	ft_init_data(t_data *data, char **argv, char **envp);
void	ft_get_cmds(t_data *data);
void	ft_child1_exec(t_data *data, char **envp);
void	ft_child2_exec(t_data *data, char **envp);
void	ft_free_data(t_data *data);
void	ft_close(int fd);
void	ft_exit(t_data *data);
int		ft_get_args_cmds(t_data *data, char *cmd1, char *cmd2);
char	*ft_get_path_cmd(char **paths_env, char *cmd);
char	**ft_path_split(char **envp);
#endif
