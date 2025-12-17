/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihad <jihad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:34:31 by jihad             #+#    #+#             */
/*   Updated: 2025/12/16 22:03:08 by jihad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *pipe_fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error_exit(argv[1]);
	if (dup2(infile, STDIN_FILENO) == -1)
		error_exit("dup2");
	close(infile);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error_exit("dup2");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_cmd(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *pipe_fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		error_exit(argv[4]);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_exit("dup2");
	close(outfile);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error_exit("dup2");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	    error_exit("Usage: ./pipex infile cmd1 cmd2 outfile");
	if (pipe(pipe_fd) == -1)
		error_exit("pipe");
	pid1 = fork();
	if (pid1 == -1)
		error_exit("fork");
	if (pid1 == 0)
		child_process(argv, envp, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		error_exit("fork");
	if (pid2 == 0)
		parent_process(argv, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
