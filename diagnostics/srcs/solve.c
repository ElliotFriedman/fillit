/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:41:54 by efriedma          #+#    #+#             */
/*   Updated: 2018/04/22 22:11:08 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check(t_tetro *piece, char **map, t_map *map1)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (isinbounds(piece, map1->size))
	{
		while (i < 4)
		{
			if (ft_isupper(map[piece->y[i]][piece->x[i]]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	place_tetri(t_tetro *piece, t_map *map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map->go[piece->y[i]][piece->x[i]] = piece->letter;
		i++;
	}
}

int		solve(t_tetro *piece, t_map *map)
{
	int		i;

	i = -1;
	if (!piece)
	{
		printf("\nSolved\n\n");
		return (1);
	}
	while (++i < ((map->size - 1) * (map->size - 1)))
	{
		if (check(piece, map->go, map))
		{
			place_tetri(piece, map);
			printf("placed piece %c\n", piece->letter);
			if (solve(piece->next, map))
				return (1);
			else
			{
				printf("removing piece %c, transforming piece to try and fit\n", piece->letter);
				ft_remove(piece->letter, map->go, map->size);
				transform(piece, map, 0);
				printf("transforming next piece to the top left corner\n");
				transform(piece->next, map, 7);
			}
		}

		else if (!transform(piece, map, 0))
		{
			printf("could not transform piece down or right, moving to top left\n");
			transform(piece, map, 7);
		}
	}
	return (0);
}

void	start(t_tetro *piece, t_map *map)
{
	while (!solve(piece, map))
	{
		printf("Could not solve on map size %d. Increasing map size to %d\nTransforming all pieces to top left hand corner\n", map->size, map->size + 1);
		plus_map(map);
		transform(piece, map, 1);
	}
	printmap(map->go, map->size);
	freemap(map->go, map->size);
	free(map);
	printf("\nAll space malloc'd freed\n");
}
