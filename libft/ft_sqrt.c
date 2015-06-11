/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:23:56 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 21:59:24 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float ft_sqrt(float num)
{
	float	a;
	float	p;
	float	e;
	float	b;
	int		nb;

	e = 0.001;
	nb = 0;
	a = num;
	p = a * a;
	while ((p - num >= e) && (nb++ < MAX_STEPS))
	{
		b = (a + (num / a)) / 2;
		a = b;
		p = a * a;
	}
	return (a);
}
