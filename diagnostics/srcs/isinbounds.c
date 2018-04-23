/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isinbounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:17:25 by efriedma          #+#    #+#             */
/*   Updated: 2018/04/05 13:31:30 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_isupper(char a)
{
	if (a >= 'A' && a <= 'Z')
		return (1);
	return (0);
}

char		**makemap(int size)
{
	char	**map;
	int		i;

	map = (char**)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map[i] = (char*)ft_memalloc(size + 1);
		map[i] = ft_memset(map[i], 46, size);
		i++;
	}
	return (map);
}

void		plus_map(t_map *map)
{
	freemap(map->go, map->size);
	map->size = map->size + 1;
	map->go = makemap(map->size);
}

void		ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int			isinbounds(t_tetro *piece, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (piece->y[i] >= size)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (piece->x[i] >= size)
			return (0);
		i++;
	}
	return (1);
}
