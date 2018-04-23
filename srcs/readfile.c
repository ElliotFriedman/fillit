/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:06:46 by emgounto          #+#    #+#             */
/*   Updated: 2018/04/22 19:21:11 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

size_t	ft_totsize(int fp)
{
	size_t	ctr;
	char	buf[1];

	ctr = 0;
	while (read(fp, buf, 1))
		ctr++;
	close(fp);
	return (ctr);
}

void	ft_verify(char **tetro, int size)
{
	int		i;
	t_tetro	*new;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->size = 2;
	i = 0;
	while (i < size)
	{
		shapevalid(tetro[i]);
		i++;
	}
	map->go = makemap(map->size);
	new = make_list(tetro, size);
	transform(new, map, 1);
	start(new, map);
	freelist(new);
}

void	ft_tetro(char *str, int size)
{
	char	**tetro;
	int		i;
	int		j;
	int		f;
	int		k;

	tetro = (char **)malloc(sizeof(char*) * ((size / 20) + 1));
	k = size % 20;
	i = (size / 20);
	j = 0;
	f = 0;
	if (!(i == k + 1) || i >= 26)
		ft_error();
	while (j < i)
	{
		tetro[j] = ft_strnew(21);
		ft_strncpy(tetro[j], &str[f], 20);
		tetro[j][21] = '\0';
		j++;
		f += 21;
	}
	tetro[j] = NULL;
	ft_verify(tetro, i);
}

void	ft_read(char *str)
{
	int		fd;
	size_t	asize;
	char	*afile;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_putstr("File is not valid\n");
	else
	{
		asize = ft_totsize(fd);
		afile = ft_strnew(asize + 1);
		fd = open(str, O_RDONLY);
		read(fd, afile, asize);
		ft_tetro(afile, asize);
		free(afile);
	}
}
