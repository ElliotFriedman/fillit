/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:42:27 by efriedma          #+#    #+#             */
/*   Updated: 2018/04/05 13:34:49 by emgounto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	push_y_up(t_tetro *target)
{
	int i;
	int min;

	i = 0;
	min = 100;
	while (i < 4)
	{
		if (target->y[i] < min)
			min = target->y[i];
		i++;
	}
	i = 0;
	if (min != 100)
	{
		while (i < 4)
		{
			target->y[i] = target->y[i] - min;
			i++;
		}
		return (1);
	}
	return (0);
}

int	push_y_down(t_tetro *target, int size)
{
	int i;
	int min;

	i = -1;
	min = 10;
	while (++i < 4)
	{
		if (target->y[i] < min)
			min = target->y[i];
		if (target->y[i] + 1 >= size)
		{
			min = 100;
			break ;
		}
	}
	if (min != 100)
	{
		i = -1;
		while (++i < 4)
			target->y[i] = target->y[i] + 1;
		return (1);
	}
	return (0);
}

int	push_x_left(t_tetro *target)
{
	int i;
	int min;
	int temp;

	i = -1;
	min = 100;
	while (++i < 4)
		if (target->x[i] < min)
			min = target->x[i];
	if (min != 100)
	{
		i = 0;
		while (i < 4)
		{
			temp = target->x[i] - min;
			target->x[i] = temp;
			i++;
		}
		return (1);
	}
	return (0);
}

int	push_x_right(t_tetro *target, int size)
{
	int i;
	int max;

	i = -1;
	max = -1;
	while (++i < 4)
	{
		if (target->x[i] > max)
			max = target->x[i];
		if (target->x[i] + 1 == size)
		{
			max = 100;
			break ;
		}
	}
	if (max != 100)
	{
		i = -1;
		while (++i < 4)
			target->x[i] = target->x[i] + 1;
		return (1);
	}
	return (0);
}

int	transform(t_tetro *target, t_map *map, int on)
{
	if (!target)
		return (0);
	else if (on == 7)
		push_all(target);
	else if (on)
	{
		while (target)
		{
			push_all(target);
			target = target->next;
		}
		return (1);
	}
	else
	{
		if (!push_x_right(target, map->size))
		{
			if (!push_y_down(target, map->size))
				return (0);
			else
				push_x_left(target);
		}
	}
	return (1);
}
