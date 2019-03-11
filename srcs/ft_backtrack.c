/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:21:28 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/11 14:21:18 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

static int	st_condition1(t_point *tab, int i, int size, char **board)
{
	if (ft_check_board1(tab, i % size, i / size, size) == 1 &&
			ft_check_board2(board, tab, i % size, i / size) == 1)
		return (1);
	return (0);
}

static int	st_condition2(t_tlist *tetri, char **board)
{
	if ((tetri->next == NULL && ft_check_place_tetri(board, tetri)) ||
			(tetri->next != NULL && ft_check_place_tetri(board, tetri->next)))
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

char		**ft_backtrack(t_tlist *tetri, char **board, int s, int i)
{
	t_point *tab;

	tab = tetri->tab;
	while ((tetri != NULL) && i <= ((s * s) - 3))
	{
		while (i <= ((s * s) - 3))
		{
			if (st_condition1(tab, i, s, board))
			{
				if (!(board = st_pose(board, st_coord(i, s), tab, tetri->name)))
					return (NULL);
				if (tetri->next)
					board = ft_backtrack(tetri->next, board, s, 0);
				break ;
			}
			i++;
		}
		if (st_condition2(tetri, board))
			break ;
		if (tetri->next != NULL && ft_check_place_tetri(board, tetri))
			if (!(board = st_pose(board, st_coord(i, s), tab, '.')))
				return (NULL);
		i++;
	}
	return (board);
}
