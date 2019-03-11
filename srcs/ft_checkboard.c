/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:28:55 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/11 16:55:29 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_is_on_board(t_point *tab, int x, int y, int size)
{
	if ((y + tab[0].y) < size && (x + tab[0].x) < size &&
			(y + tab[1].y) < size && (x + tab[1].x) < size &&
			(y + tab[2].y) < size && (x + tab[2].x) < size &&
			(y + tab[3].y) < size && (x + tab[3].x) < size)
		return (1);
	else
		return (0);
}

int	ft_is_empty(char **board, t_point *tab, int x, int y)
{
	if (board[y + tab[0].y][x + tab[0].x] == '.' &&
			board[y + tab[1].y][x + tab[1].x] == '.' &&
			board[y + tab[2].y][x + tab[2].x] == '.' &&
			board[y + tab[3].y][x + tab[3].x] == '.')
		return (1);
	else
		return (0);
}
