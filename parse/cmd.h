/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:06:57 by eel-orch          #+#    #+#             */
/*   Updated: 2021/05/01 15:01:02 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# define SIMPLE_REDIRECTION 1
# define DOUBLE_REDIRECTION 2

typedef struct s_escapes
{
	int				d_q;
	int				s_q;
	int				b_s;
}					t_escapes;

typedef struct s_output
{
	int				type;
	char			*file;
	struct s_output	*next;
}					t_output;

typedef struct s_input
{
	char			*file;
	struct s_input	*next;
}					t_input;

typedef struct s_cmd
{
	char			*name;
	char			*option;
	char			**args;
	t_input			*input;	
	t_output		*output;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_repenv
{
	int			*i;
	t_escapes	escp;
}				t_repenv;

typedef struct s_clean
{
	int			i;
	int			j;
	t_escapes	escp;
}				t_clean;

#endif
