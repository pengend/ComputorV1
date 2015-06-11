/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 18:05:33 by pxia              #+#    #+#             */
/*   Updated: 2015/06/11 21:54:42 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPV1_H
# define CPV1_H
# define MAX_POL 3
# define MAX_AS 100
# define ROOT "\u221A"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

typedef struct s_pol
{
	float num;
	int deg;
}		t_pol;

typedef struct s_opr
{
	t_pol left[MAX_AS];
	t_pol right[MAX_AS];
	t_pol *fin;
	int max;
	float dis;
	float x1;
	float x2;
	int l_len;
	int r_len;
	int f_len;
}		t_opr;

void get_opr(t_opr *sides, char *operation);
void calq_fin_branch(t_opr *sides);
void put_reduced_form(t_opr *sides);
void put_solution(t_opr *sides);
void degree_two(t_opr *sides);
void degree_one(t_opr *sides);
void put_solution_deg_two(t_opr *sides);
void put_solution_deg_one(t_opr *sides);
void polynome_gestion(t_opr *sides);
float ft_sqrt(float num);
int check_format(char *operation);
int check_character(char *operation);
void trie_fin_branch(t_opr *sides);

#endif
