/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:17:07 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/25 14:57:45 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include "../libft/libft.h"
# include "../structs.h"
# include <sys/ioctl.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# define TRUE 1

typedef struct s_flags
{
	int		esc;
	int		l_br;
	char	ltr;
}				t_flags;

typedef struct s_winsize
{
	int			w_row;
	int			w_col;
	int			w_xpixels;
	int			w_ypixels;
}				t_winsize;

typedef struct s_read_tools
{
	t_winsize	win_info;
	int			nb_line;
	char		*tmp;
	t_flags		fl;
}			t_read_tools;

/*
 * prototypes for read_line.c file
 */

char	*read_line();
char	*just_read(t_read_tools *rt);
char	*add_buffer(t_read_tools *rt);

/*
 * prototypes for check_flags.c file
 */

int		check_flags(char c, t_flags *fl);
void	apply_flags(char **buff, t_flags *fl);

/*
 * prototypes for format_terminal.c file
 */

int		init_terminal_data(void);
int		format_terminal(struct termios *orig);
int		reset_terminal(struct termios *orig);
int		get_termios(struct termios *term);
int		set_termios(struct termios *term, int flag);

/*
 * prototypes for delete_char.c file
 */

void	delete_char(char **buff);
void	clear_line(char *buff);

/*
 * prototypes for quit_d.c file
 */

void	quit_d(t_read_tools *rt);
char	*quit_delete(t_read_tools *rt);

/*
 * prototypes for history_functions.c file
 */

void	up_arrow(char **buff);
void	down_arrow(char **buff);
int     get_wininfo(t_winsize *win_info);

/*
 * prototypes for signal_handler.c file
 */

void	signal_handler(void);
void	ctrl_c_handler(int sig);
void	ctrl_bs_handler(int sig);

/*
 * prototypes for check_line_errors.c file
 */

int		check_line_errors(char *line);

#endif
