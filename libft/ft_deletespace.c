/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deletespace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 17:08:21 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 21:58:49 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_char(char *s)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			ret++;
		i++;
	}
	return (ret);
}

char	*ft_deletespace(char *s)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = ft_strnew(count_char(s));
	while (s[i])
	{
		if (s[i] != '\t' && s[i] != ' ')
		{
			ret[j] = s[i];
			j++;
		}
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
