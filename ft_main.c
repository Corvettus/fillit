/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 02:11:54 by tlynesse          #+#    #+#             */
/*   Updated: 2019/04/11 20:30:25 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetro.h"

int		main(int ac, char **av)
{
	int			number;
	t_tetros	*ft_figset;

	number = 0;
	ft_figset = NULL;
	if (ac != 2)
		write(1, "usage: ./fillit source_file\n", 28);
	else if (!(number = ft_validator(av[1], &ft_figset)))
		write(1, "error\n", 6);
	else
		ft_fill(ft_figset, 4 * number);
	return (0);
}
