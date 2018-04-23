/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:11:10 by efriedma          #+#    #+#             */
/*   Updated: 2018/04/05 14:09:53 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_remove(char a, char **map, int size)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (x < size)
	{
		if (map[x][i] == a)
			map[x][i] = '.';
		i++;
		if (i == size)
		{
			i = 0;
			x++;
		}
	}
}

void	printmap(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
}

void	freelist(t_tetro *piece)
{
	t_tetro *tmp;

	tmp = NULL;
	while (piece)
	{
		tmp = piece;
		piece = piece->next;
		free(tmp);
	}
}

void	freemap(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		map[i] = 0;
		i++;
	}
	free(map);
}
