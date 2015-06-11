/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:09:41 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 19:56:19 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.h"

int check_character(char *operation)
{
	int i;
	int eq;

	i = 0;
	eq = 0;
	while (operation[i])
	{
		if (operation[i] == '=')
		{
			if (eq == 0)
				eq = 1;
			else
				return (0);
		}
		if (!ft_isdigit(operation[i]) && operation[i] != '*' &&
			operation[i] != '+' && operation[i] != '-' && operation[i] != 'X'
			&& operation[i] != 'x' && operation[i] != '^'
			&& operation[i] != '=' && operation[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int signe_verif(char *operation, int i)
{
	if (operation[i] == '.' &&
	(!ft_isdigit(operation[i - 1]) || !ft_isdigit(operation[i + 1])))
		return (0);
	else if ((!ft_isdigit(operation[i - 1]) && operation[i - 1] != 'X' &&
	operation[i - 1] != 'x') || (!ft_isdigit(operation[i + 1])
	&& operation[i + 1] != 'X' && operation[i + 1] != 'x'))
		return (0);
	return (1);
}

int check_format(char *operation)
{
	int i;

	i = 1;
	if (!ft_isdigit(operation[0]) && operation[0] != '+' && operation[0] != '-')
		return (0);
	while (operation[i])
	{
		if (operation[i] == 'X' || operation[i] == 'x')
		{
			if (operation[i + 1] != '^')
				return (0);
		}
		else if (!ft_isdigit(operation[i]) && operation[i] != '=' &&
		operation[i - 1] != '=')
		{
			if (!signe_verif(operation, i))
				return (0);
		}
		i++;
	}
	return (1);
}
