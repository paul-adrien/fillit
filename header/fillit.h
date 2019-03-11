/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:39:54 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/11 14:24:11 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tlist
{
	t_point			*tab;
	char			name;
	struct s_tlist	*next;
}				t_tlist;

int				ft_check_board2(char **board, t_point *tab, int x, int y);
int				ft_check_board1(t_point *tab, int x, int y, int size);
void			ft_dellist(t_tlist **alst);
char			**ft_tetriplace(t_tlist *tetrilist, int tetrinb);
char			**ft_backtrack(t_tlist *tetri, char **board, int size, int i);
int				ft_check_place_tetri(char **board, t_tlist *tetri);
void			ft_printboard(char **board);
t_point			*ft_idtetri(char *str);
int				ft_check(char *str, int n);
t_tlist			*ft_newtetri(t_tlist *tetrilist, char *str, int tetrinb);
int				get_next_line(const int fd, char **line);
#endif
