/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dellist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:23:50 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/12 17:07:50 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_dellist(t_tlist **alst)
{
	t_tlist *temp;

	if (alst)
	{
		while (*alst)
		{
			temp = (*alst)->next;
			free((*alst)->tab);
			free(*alst);
			*alst = temp;
		}
	}
	return (1);
}
