/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgounto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:36:41 by emgounto          #+#    #+#             */
/*   Updated: 2018/04/22 19:34:43 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_usage(void)
{
	ft_putstr("usage: ./fillit input_file\n");
	exit(0);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		ft_read(argv[1]);
	else
		ft_usage();
	return (0);
}
