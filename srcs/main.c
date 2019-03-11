/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:00:03 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/11 18:43:32 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		st_print_error(int argc, int linenb, int mode)
{
	if (mode == 1 && argc != 2)
	{
		ft_putstr("usage: one argument needed\n");
		return (0);
	}
	else if (mode == 2 && linenb != 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	else if (mode == 3)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

static int		st_tetri_nb(t_tlist *tetrilist)
{
	int		tetrinb;
	t_tlist	*tetritmp;

	tetritmp = tetrilist;
	tetrinb = 0;
	while (tetritmp != NULL)
	{
		tetritmp = tetritmp->next;
		tetrinb++;
	}
	if (tetrinb >= 27)
		st_print_error(0, 0, 3);
	return (tetrinb);
}

static t_tlist	*st_get_tetrilist
	(int fd, t_tlist *tetrilist, char *str, char *line)
{
	int	linenb;

	linenb = 1;
	while (get_next_line(fd, &line) == 1)
	{
		str = ft_strcat(str, line);
		if (linenb == 0 && ft_check(str, 1) == 0)
			return (0);
		free(line);
		if (linenb == 4)
		{
			linenb = 0;
			if (ft_check(str, 2) == 0 || (!(tetrilist = ft_newtetri(tetrilist,
								str, st_tetri_nb(tetrilist)))))
				return (0);
			bzero(str, 16);
		}
		else
			linenb++;
	}
	free(line);
	if (!(st_print_error(0, linenb, 2)))
		return (0);
	return (tetrilist);
}

int				main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char	*line;
	char	**board;
	t_tlist	*tetrilist;

	tetrilist = NULL;
	line = NULL;
	if (st_print_error(argc, 0, 1) == 0
		|| (fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (!(str = ft_strnew(16))
		|| !(tetrilist = st_get_tetrilist(fd, tetrilist, str, line)))
		return (0);
	free(str);
	free(line);
	if (!(board = ft_set_board(tetrilist, st_tetri_nb(tetrilist))))
		return (0);
	ft_printboard(board);
	ft_dellist(&tetrilist);
	close(fd);
	return (0);
}
