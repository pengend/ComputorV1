/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 19:16:03 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 21:57:01 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.h"

void put_reduced_form(t_opr *sides)
{
	int i;

	ft_putstr("Reduced form : ");
	i = 0;
	while (i < sides->f_len)
	{
		if (sides->fin[i].num != 0)
		{
			if (i == 0 && sides->fin[i].num < 0)
				ft_putchar('-');
			else if (sides->fin[i].num < 0)
				ft_putstr(" - ");
			else if (i != 0)
				ft_putstr(" + ");
			ft_putfloat(ABS(sides->fin[i].num), 5);
			ft_putstr(" * X^");
			ft_putnbr(sides->fin[i].deg);
		}
		i++;
	}
	ft_putstr(" = 0\nPolynomial degree: ");
	ft_putnbr(sides->max);
}

void ft_putsolution(t_opr *sides)
{
	float a;
	float b;
	float c;

	a = sides->fin[0].num;
	b = sides->fin[1].deg == 1 ? sides->fin[1].num : 0;
	c = sides->fin[1].deg == 0 ? sides->fin[1].num : sides->fin[2].num;
	ft_putstr("\nDiscriminat is strictly negative, no solution in R\n");
	ft_putstr("(");
	ft_putfloat(-b, 4);
	ft_putstr(" - i");
	ft_putstr(" - i/-");
	ft_putfloat(-sides->dis, 5);
	ft_putstr(") / ");
	ft_putfloat(2 * a, 4);
	ft_putchar('\n');
	ft_putstr("(");
	ft_putfloat(-b, 4);
	ft_putstr(" + i/-");
	ft_putfloat(-sides->dis, 5);
	ft_putstr(") / ");
	ft_putfloat(2 * a, 4);
	ft_putchar('\n');
}

void put_solution_deg_two(t_opr *sides)
{
	ft_putstr(" Discriminant : ");
	ft_putfloat(sides->dis, 5);
	if (sides->dis > 0)
	{
		ft_putstr
		("\nDiscriminant is strictly positive, the two solutions are: \n");
		ft_putfloat(sides->x1, 5);
		ft_putchar('\n');
		ft_putfloat(sides->x2, 5);
		ft_putchar('\n');
	}
	else if (sides->dis == 0)
	{
		ft_putstr("\nDiscriminant is null, the unique solution is: \n");
		ft_putfloat((sides->fin[1].num / 2.0 / sides->fin[0].num * -1), 5);
		ft_putchar('\n');
	}
	else
		ft_putsolution(sides);
}

void put_solution_deg_one(t_opr *sides)
{
	if (sides->max == 0)
	{
		if (sides->fin[0].num)
			ft_putendl("\nThis equation is false");
		else
			ft_putendl("\nEvery value of X is possible");
	}
	else
	{
		ft_putendl("\nThe solution is : ");
		ft_putfloat(sides->x1, 5);
		ft_putchar('\n');
	}
}
