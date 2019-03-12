/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_IDtetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:06:39 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/12 15:12:01 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_point	*st_set_tab(void)
{
	int		i;
	t_point *tab;

	tab = (t_point*)malloc(sizeof(t_point) * (4 + 1));
	i = 0;
	while (i < 5)
	{
		tab[i].x = 0;
		tab[i].y = 0;
		i++;
	}
	return (tab);
}

static t_point	*st_move(t_point *tab, char *str, int initx)
{
	int		i;
	int		j;
	int		inity;

	i = 0;
	j = 0;
	inity = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			tab[j].x = i % 4;
			tab[j].y = i / 4;
			if (j == 0)
			{
				initx = tab[0].x;
				inity = tab[0].y;
			}
			tab[j].x = tab[j].x - initx;
			tab[j].y = tab[j].y - inity;
			j++;
		}
		i++;
	}
	return (tab);
}

t_point			*ft_idtetri(char *str)
{
	t_point	*tab;
	int		j;
	int		initx;

	j = 0;
	initx = 0;
	if (!(tab = st_set_tab()))
		return (0);
	tab = st_move(tab, str, initx);
	while (j < 4)
	{
		j++;
		if (tab[j].x < 0)
		{
			initx = tab[j].x;
			j = 0;
			while (j < 4)
			{
				tab[j].x = tab[j].x - initx;
				j++;
			}
		}
	}
	return (tab);
}
