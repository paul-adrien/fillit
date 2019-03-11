/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:09:35 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/11 14:28:36 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

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

char		**ft_tetriplace(t_tlist *tetrilist, int tetrinb)
{
	char 	**board;
	int		size;
	int		i;

	size = st_nearsqrt(tetrinb * 4);
	board = st_create_board(size);
	board = ft_backtrack(tetrilist, board, size, 0);
	while (!ft_check_place_tetri(board, tetrilist))
	{
		i = 0;
		while (i < (size + 1))
		{
			free(board[i]);
			i++;
		}
		free(board);
		size++;
		board = st_create_board(size);
		board = ft_backtrack(tetrilist, board, size, 0);
	}
	return (board);
}
