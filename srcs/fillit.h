/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:39:54 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/12 16:09:05 by plaurent         ###   ########.fr       */
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

int				ft_is_empty(char **board, t_point *tab, int x, int y);
int				ft_is_on_board(t_point *tab, int x, int y, int size);
int				ft_dellist(t_tlist **alst);
char			**ft_set_board(t_tlist *tetrilist, int tetrinb);
char			**ft_fill(t_tlist *tetri, char **board, int size, int i);
int				ft_tetri_is_placed(char **board, t_tlist *tetri);
void			ft_printboard(char **board);
t_point			*ft_idtetri(char *str);
int				ft_check(char *str, int n);
t_tlist			*ft_newtetri(t_tlist *tetrilist, char *str, int tetrinb);
#endif
