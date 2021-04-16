/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 08:35:02 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/16 10:37:12 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_env(t_builtin_vars var, int *retv)
{
	int		i;
	char	**envp;

	i = 0;
	envp = *(var.envp);
	while (envp != NULL && envp[i] != NULL)
	{
		if (ft_isenv(envp[i]))
		{
			write(1, envp[i], ft_strlen(envp[i]));
			if (envp[i + 1] != NULL)
				write(1, "\n", 1);
		}
		i++;
	}
	*retv = 0;
	// protection of write when env fails
}

//int main(int argc, char **args, char **envp)
//{
//	t_builtin_vars var;
//	int retv;
//
//	var.args = NULL;
//	var.envp = &envp;
//	var.option = NULL;
//	ft_env(var, &retv);
//}
