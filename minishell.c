/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:03:49 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/21 16:17:24 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     main(int argc, char **argv, char **envp)
{
	char		*command_line;
	char		retv;
	t_history	hist;
    
    write(1, "\e[1;1H\e[2J", 11);
	retv = 0;
	hist.fd = open_history();	
	hist = read_history(hist.fd);
    if (argc == 1 && argv != NULL && envp != NULL)
    {
        while (TRUE)
        {
			hist.pos = hist.size;
			hist.wr = 0;
			command_line = read_line(&hist);
			write(1, "\n", 1);
			retv = parse_execute(ft_strdup(command_line), envp, retv);
			//write(1, "\n", 1);
			//write(1, command_line, ft_strlen(command_line));
			write(1, "\n", 1);
			write_history(&hist, ft_strdup(command_line));
			free(command_line);
        }
	}
}
