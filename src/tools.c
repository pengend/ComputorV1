/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 18:03:33 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 22:06:25 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.h"

t_pol	get_pol(char *operation)
{
	t_pol	pol;
	int		i;

	pol.num = ft_fatoi(operation);
	i = 1;
	while (operation[i] && (ft_isdigit(operation[i]) || operation[i] == '.'))
		i++;
	if (operation[i] == '+' || operation[i] == '-' || operation[i] == '=')
		pol.deg = 0;
	else
		pol.deg = ft_atoi(operation + i + 3);
	return (pol);
}

int		get_next_signe(char *operation)
{
	int i;

	i = 0;
	while (operation[i] && operation[i] != '+' && operation[i] != '-'
	&& operation[i] != '=')
		i++;
	return (i);
}

void	sides_init(t_opr *sides)
{
	int i;

	i = 0;
	while (i < MAX_AS)
	{
		sides->left[i].num = 0;
		sides->left[i].deg = 0;
		sides->right[i].num = 0;
		sides->right[i].deg = 0;
		i++;
	}
}

void	reduce_member(t_pol *pols, int *len)
{
	int i;
	int j;

	i = 0;
	while (i < *len)
	{
		j = i + 1;
		while (j < *len)
		{
			if (pols[j].deg == pols[i].deg)
			{
				pols[i].num += pols[j].num;
				pols[j].num = 0;
			}
			j++;
		}
		i++;
	}
}

void	get_opr(t_opr *sides, char *operation)
{
	int i;

	sides->l_len = 0;
	sides->r_len = 0;
	i = 0;
	sides_init(sides);
	while (operation[i] && operation[i] != '=')
	{
		sides->left[sides->l_len] = get_pol(operation + i);
		i++;
		i += get_next_signe(operation + i);
		sides->l_len++;
	}
	i++;
	while (operation[i])
	{
		sides->right[sides->r_len] = get_pol(operation + i);
		i++;
		i += get_next_signe(operation + i);
		sides->r_len++;
	}
	reduce_member(sides->left, &(sides->l_len));
	reduce_member(sides->right, &(sides->r_len));
}
