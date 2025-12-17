/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihad <jihad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:35:19 by jihad             #+#    #+#             */
/*   Updated: 2025/12/16 03:13:30 by jihad            ###   ########.fr       */
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

/* utils_error.c */
void	error_exit(char *message);
void	ft_putstr_fd(char *s, int fd);
void	free_split(char **split);
void	full_free(char *str, char **arr);

/* utils.c */
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* ft_split.c */
char	**ft_split(char const *s, char c);

/* utils2.c - path and execute */
char	*find_path(char *cmd, char **envp);
void	execute_cmd(char *argv, char **envp);

/* process_functions.c */
void	child_process(char **argv, char **envp, int *pipe_fd);
void	parent_process(char **argv, char **envp, int *pipe_fd);

#endif