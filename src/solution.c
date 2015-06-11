/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:47:28 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 21:38:48 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.h"

void degree_two(t_opr *sides)
{
	float a;
	float b;
	float c;
	float d;

	a = sides->fin[0].num;
	b = sides->fin[1].deg == 1 ? sides->fin[1].num : 0;
	c = sides->fin[1].deg == 0 ? sides->fin[1].num : sides->fin[2].num;
	d = 2 * a;
	sides->dis = b * b - 4 * a * c;
	if (sides->dis > 0)
	{
		sides->x1 = ((float)-b - ft_sqrt((float)sides->dis)) / d;
		sides->x2 = ((float)-b + ft_sqrt((float)sides->dis)) / d;
	}
	else
	{
		sides->x1 = 0;
		sides->x2 = 0;
	}
}

void degree_one(t_opr *sides)
{
	float a;
	float b;

	a = sides->fin[0].deg == 1 ? sides->fin[0].num : sides->fin[1].num;
	b = sides->fin[1].deg == 0 ? sides->fin[1].num : sides->fin[2].num;
	if (!b)
		sides->x1 = 0;
	else
		sides->x1 = -b / 1.0 / a;
}

void polynome_gestion(t_opr *sides)
{
	put_reduced_form(sides);
	if (sides->max == 2)
	{
		degree_two(sides);
		put_solution_deg_two(sides);
	}
	else if (sides->max < 2)
	{
		degree_one(sides);
		put_solution_deg_one(sides);
	}
	else
		ft_putendl(
		"\nThe polynomial degree is stricly greater than 2, I can't solve");
}
