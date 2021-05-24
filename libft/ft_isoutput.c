/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoutput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:38:16 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/01 12:06:18 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isoutput(char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] != '>')
			return (-1);
		i++;
	}
	return (i);
}
