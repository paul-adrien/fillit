/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:55:32 by eviana            #+#    #+#             */
/*   Updated: 2019/03/11 17:55:36 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	st_place_available(t_point *tab, int i, int size, char **board)
{
	if (ft_is_on_board(tab, i % size, i / size, size) == 1 &&
			ft_is_empty(board, tab, i % size, i / size) == 1)
		return (1);
	return (0);
}

static int	st_last_tetri_is_placed(t_tlist *tetri, char **board)
{
	if ((tetri->next == NULL && ft_tetri_is_placed(board, tetri)) ||
			(tetri->next != NULL && ft_tetri_is_placed(board, tetri->next)))
		return (1);
	return (0);
}

static char	**st_pose(char **board, int *tab2, t_point *tab, char c)
{
	int		x;
	int		y;

	if (!tab)
		return (NULL);
	y = tab2[0];
	x = tab2[1];
	board[y + tab[0].y][x + tab[0].x] = c;
	board[y + tab[1].y][x + tab[1].x] = c;
	board[y + tab[2].y][x + tab[2].x] = c;
	board[y + tab[3].y][x + tab[3].x] = c;
	free(tab2);
	return (board);
}

static int	*st_coord(int i, int size)
{
	int		*tab2;

	if (!(tab2 = malloc(sizeof(int) * 2)))
		return (NULL);
	tab2[0] = i / size;
	tab2[1] = i % size;
	return (tab2);
}

char		**ft_fill(t_tlist *tetri, char **board, int s, int i)
{
	t_point *tab;

	tab = tetri->tab;
	while ((tetri != NULL) && i <= ((s * s) - 3))
	{
		while (i <= ((s * s) - 3))
		{
			if (st_place_available(tab, i, s, board))
			{
				if (!(board = st_pose(board, st_coord(i, s), tab, tetri->name)))
					return (NULL);
				if (tetri->next && !(board = ft_fill(tetri->next, board, s, 0)))
					return (NULL);
				break ;
			}
			i++;
		}
		if (st_last_tetri_is_placed(tetri, board))
			break ;
		if (tetri->next != NULL && ft_tetri_is_placed(board, tetri))
			if (!(board = st_pose(board, st_coord(i, s), tab, '.')))
				return (NULL);
		i++;
	}
	return (board);
}
