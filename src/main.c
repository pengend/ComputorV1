/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 18:03:43 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 22:18:05 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpv1.h"

void	calq(char *equation)
{
	t_opr sides;

	get_opr(&sides, equation);
	calq_fin_branch(&sides);
	trie_fin_branch(&sides);
	polynome_gestion(&sides);
}

int		loop(void)
{
	char *line;
	char equation[100000];
	char *tmp;

	ft_putstr("\033[1m\x1B[35mLOOP MODE\033[0m\n");
	while (1)
	{
		bzero(equation, 100000);
		get_next_line(0, &line);
		if (!ft_strcmp(line, "quit"))
			return (0);
		ft_strcpy(equation, (tmp = ft_deletespace(line)));
		free(tmp);
		free(line);
		if (!check_character(equation) || !check_format(equation))
		{
			ft_putstr("\033[1m\x1B[31mError : Format\n\033[0m");
			continue ;
		}
		ft_putstr(C_BGREEN);
		calq(equation);
		ft_putstr(C_RESET);
	}
}

int		main(int ac, char **av)
{
	char *equation;

	if (ac == 1)
		return (loop());
	else if (ac > 2)
		return (0);
	equation = ft_deletespace(av[1]);
	ft_sys("Verifying characters", 1, 1, check_character(equation));
	ft_sys("Verifying format", 1, 1, check_format(equation));
	ft_putstr(C_BOLD);
	calq(equation);
	ft_putstr(C_RESET);
	return (0);
}
