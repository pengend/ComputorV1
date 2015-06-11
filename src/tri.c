/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:48:53 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 21:40:10 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.h"

int		find_min(t_pol *fin, int len)
{
	int min;

	min = len;
	while (len--)
	{
		if (fin[min].deg > fin[len].deg)
			min = len;
	}
	return (min);
}

void	ft_cswap(t_pol *fin, int a, int b)
{
	t_pol tmp;

	tmp = fin[a];
	fin[a] = fin[b];
	fin[b] = tmp;
}

void	trie_fin_branch(t_opr *sides)
{
	int len;

	len = sides->f_len;
	while (len-- > 0)
	{
		ft_cswap(sides->fin, find_min(sides->fin, len), len);
	}
}
