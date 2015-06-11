/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 18:12:20 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 21:58:59 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float check_dot(char *s)
{
	int i;
	int dot;

	i = 0;
	dot = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == '.'))
	{
		if (s[i] == '.' && dot == 0)
			dot = i;
		else if (s[i] == '.' && dot != 0)
			return (0);
		i++;
	}
	if (!dot)
		return (dot);
	return (dot);
}

float ft_fatoi(char *s)
{
	int		i;
	float	ret;
	float	f;
	float	tmp;
	float	sig;

	sig = 1;
	if (s[0] == '-')
		sig = -1;
	if (!(i = check_dot(s)))
		return ((float)ft_atoi(s));
	ret = ft_atoi(s);
	f = 0.1;
	i++;
	while (s[i] && ft_isdigit(s[i]))
	{
		tmp = s[i] - 48;
		ret += tmp * f * sig;
		f /= 10;
		i++;
	}
	return (ret);
}
