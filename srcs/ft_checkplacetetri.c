/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place_tetri.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:28:50 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/11 14:08:24 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

int		ft_check_place_tetri(char **board, t_tlist *tetri)
{
	int i;
	int j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			if (board[i][j] == tetri->name)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
