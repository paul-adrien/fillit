/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:35:18 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/11 14:27:12 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

static t_tlist	*st_create_tetri(t_point *tab, int tetrinb)
{
	t_tlist	*tetri;

	if (!(tetri = (t_tlist*)malloc(sizeof(t_tlist))))
		return (NULL);
	if (tab)
	{
		if (!(tetri->tab = (void*)malloc(sizeof(t_point) * (5))))
		{
			free(tetri);
			return (NULL);
		}
		ft_memcpy(tetri->tab, tab, (sizeof(t_point) * 5));
		tetri->name = (char)tetrinb + 'A';
	}
	else
	{
		tetri->tab = NULL;
		tetri->name = 0;
	}
	tetri->next = NULL;
	return (tetri);
}

t_tlist			*ft_newtetri(t_tlist *tetrilist, char *str, int tetrinb)
{
	t_tlist	*tetri;
	t_tlist	*templist;
	t_point	*tab;

	tab = ft_idtetri(str);
	tetri = st_create_tetri(tab, tetrinb);
	free(tab);
	tab = NULL;
	if (tetrilist == NULL)
		return (tetri);
	else
	{
		templist = tetrilist;
		while (templist->next != NULL)
			templist = templist->next;
		templist->next = tetri;
		return (tetrilist);
	}
}
