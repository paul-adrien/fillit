/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:05:29 by eviana            #+#    #+#             */
/*   Updated: 2019/03/11 14:22:35 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

static int	st_check_place(char *str, int i)
{
	int	j;

	j = 0;
	if (i > 3)
		if (str[i - 4] == '#')
			j++;
	if (i != 3 && i != 7 && i != 11 && i != 15)
		if (str[i + 1] == '#')
			j++;
	if (i < 12)
		if (str[i + 4] == '#')
			j++;
	if (i != 0 && i != 4 && i != 8 && i != 12)
		if (str[i - 1] == '#')
			j++;
	return (j);
}

static int	st_check_nb(char *str)
{
	int	i;
	int	nb;
	int	k;

	i = 0;
	nb = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			nb++;
		if (str[i] == '.' || str[i] == '#')
			k++;
		i++;
	}
	if (nb == 4 && k == 16 && i == 16)
		return (1);
	return (0);
}

static int	st_check_tetri(char *str)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
			n = n + st_check_place(str, i);
	}
	if (n < 6)
		return (0);
	return (1);
}

int			ft_check(char *str, int n)
{
	if (n == 1 && str[0] != '\0')
	{
		ft_putstr("error\n");
		return (0);
	}
	if (n == 2)
	{
		if (st_check_nb(str) == 0)
		{
			ft_putstr("error\n");
			return (0);
		}
		if (st_check_tetri(str) == 0)
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	return (1);
}
