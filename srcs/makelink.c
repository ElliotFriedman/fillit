/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:33:45 by efriedma          #+#    #+#             */
/*   Updated: 2018/04/22 19:18:47 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	push_all(t_tetro *target)
{
	push_y_up(target);
	push_x_left(target);
}

void	find_coord(char **dptr, t_tetro *piece)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (y < 4)
	{
		if (dptr[y][x] == '#')
		{
			piece->y[i] = y;
			piece->x[i] = x;
			i++;
		}
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
	}
}

void	one2(char *str, t_tetro *link)
{
	char	**dptr;
	int		i;
	int		ctr;

	ctr = 0;
	i = 0;
	dptr = ft_memalloc(sizeof(char*) * 4);
	while (i < 4)
	{
		dptr[i] = ft_strnew(4);
		ft_strncpy(dptr[i], &str[ctr], 4);
		ctr += 5;
		i++;
	}
	find_coord(dptr, link);
	freemap(dptr, 4);
}

t_tetro	*make_list(char **tetro, int size)
{
	t_tetro		*snew;
	t_tetro		*buf;
	int			i;

	i = 0;
	snew = (t_tetro*)malloc(sizeof(t_tetro));
	buf = snew;
	while (i < size)
	{
		one2(tetro[i], snew);
		snew->letter = 'A' + i;
		if (i + 1 == size)
		{
			snew->next = 0;
			break ;
		}
		else
			snew->next = (t_tetro*)malloc(sizeof(t_tetro));
		snew = snew->next;
		i++;
	}
	freemap(tetro, size);
	return (buf);
}
