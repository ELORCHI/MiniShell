/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:45:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/25 21:42:00 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

/*
 * delete_char: uses termcap capabilities to:
 * move the cursor to left one character with 'le' capability
 * delete character on right with 'dc' capability
 * only if buffer contain enough characters
*/

void	delete_char(char **buff, t_termcapab capab)
{
	int		len;

	len = ft_strlen(*buff);
	if (len > 0)
	{
		(*buff)[len - 1] = '\0';
		tputs(capab.move_left, 1, ft_putchar);
		tputs(capab.del_one, 1, ft_putchar);
	}
}

/*
 * clear_line: uses termcap to delete line from terminal
 * and prompt again
*/

void	clear_line(char *buff, t_read_tools *rt)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(buff);
	while (i < rt->nb_line)
	{
		tputs(rt->capab.up_line, 1, ft_putchar);
		len -= rt->win_info.ts_cols;
		i++;
	}
	while (len > 0)
	{
		tputs(rt->capab.move_left, 1, ft_putchar);
		len--;
	}
	tputs(rt->capab.clear_scr, 1, ft_putchar);
}
