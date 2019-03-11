/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:40:38 by eviana            #+#    #+#             */
/*   Updated: 2019/03/11 21:07:07 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	st_nearsqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i < nb && i <= 46340)
		i++;
	return (i);
}

static char	**st_create_board(int size)
{
	char	**board;
	int		x;
	int		y;

	y = 0;
	if (!(board = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		x = 0;
		if (!(board[y] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (x < size)
		{
			board[y][x] = '.';
			x++;
		}
		board[y][x] = '\0';
		y++;
	}
	board[y] = NULL;
	return (board);
}

char		**ft_set_board(t_tlist *tetrilist, int tetrinb)
{
	char	**board;
	int		size;
	int		i;

	size = st_nearsqrt(tetrinb * 4);
	if (tetrinb >= 27 || !(board = st_create_board(size)))
		return (NULL);
	if (!(board = ft_fill(tetrilist, board, size, 0)))
		return (NULL);
	while (!ft_tetri_is_placed(board, tetrilist))
	{
		i = 0;
		while (i < (size + 1))
		{
			free(board[i]);
			i++;
		}
		free(board);
		size++;
		if (!(board = st_create_board(size)))
			return (NULL);
		if (!(board = ft_fill(tetrilist, board, size, 0)))
			return (NULL);
	}
	return (board);
}
