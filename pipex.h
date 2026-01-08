/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:43:56 by jalju-be          #+#    #+#             */
/*   Updated: 2025/12/31 17:02:01 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

void	error_exit(char *message);
void	ft_putstr_fd(char *s, int fd);
void	free_split(char **split);
void	error_dup(int *pipe_fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*find_path(char *cmd, char **envp);
void	execute_cmd(char *argv, char **envp);
void	child_process(char **argv, char **envp, int *pipe_fd);
void	parent_process(char **argv, char **envp, int *pipe_fd);

#endif