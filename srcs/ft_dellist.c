/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dellist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:23:50 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/11 14:08:42 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fillit.h"

void	ft_dellist(t_tlist **alst)
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
}
