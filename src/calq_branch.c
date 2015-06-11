/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calq_branch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 18:28:23 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 21:36:06 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.h"

t_pol	get_same_deg(t_opr *sides, int deg)
{
	int		i;
	t_pol	tmp;

	i = 0;
	tmp.num = 0;
	tmp.deg = deg;
	while (i < sides->r_len)
	{
		if (sides->right[i].deg == deg && sides->right[i].num)
		{
			tmp = sides->right[i];
			sides->right[i].num = 0;
			return (tmp);
		}
		else if (deg == -1 && (sides->right[i].num))
		{
			tmp = sides->right[i];
			sides->right[i].num = 0;
			return (tmp);
		}
		i++;
	}
	return (tmp);
}

t_pol	add_same_deg(t_opr *sides)
{
	t_pol	tmp;
	t_pol	tmp2;
	int		i;

	i = 0;
	tmp.num = 0;
	tmp.deg = -1;
	while (i < sides->l_len)
	{
		if (sides->left[i].num)
		{
			tmp.num += sides->left[i].num;
			tmp.deg = sides->left[i].deg;
			sides->left[i].num = 0;
			break ;
		}
		i++;
	}
	tmp2 = get_same_deg(sides, tmp.deg);
	tmp.num -= tmp2.num;
	tmp.deg = tmp2.deg;
	return (tmp);
}

void	calq_fin_branch(t_opr *sides)
{
	int i;

	sides->f_len = sides->l_len + sides->r_len;
	i = sides->f_len;
	sides->max = 0;
	sides->fin = (t_pol*)malloc(sizeof(t_pol) * sides->f_len);
	while (i >= 0)
	{
		sides->fin[i].num = 0;
		sides->fin[i].deg = 0;
		i--;
	}
	i = 0;
	while (i < sides->f_len)
	{
		sides->fin[i] = add_same_deg(sides);
		if (sides->fin[i].num)
			sides->max =
			sides->fin[i].deg > sides->max ? sides->fin[i].deg : sides->max;
		i++;
	}
}
