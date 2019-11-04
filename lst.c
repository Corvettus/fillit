/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:24:33 by medesmon          #+#    #+#             */
/*   Updated: 2019/04/11 20:31:13 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetro.h"

static void		lst_add_last(t_tetros **alst, t_tetros *new)
{
	t_tetros	*tmp;

	if ((*alst) && new)
	{
		tmp = (*alst);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		tmp->next->prev = tmp;
	}
	if (!(*alst) && new)
		(*alst) = new;
}

static void		find_min_x(t_tetros **list)
{
	int	i;
	int min_x;

	i = 0;
	min_x = 4;
	while (i != 4)
	{
		if (((*list)->cell)[i].x < min_x)
			min_x = ((*list)->cell)[i].x;
		i++;
	}
	if (min_x > 0)
	{
		i = 0;
		while (i != 4)
		{
			((*list)->cell)[i].x -= min_x;
			i++;
		}
	}
}

static void		find_min_y(t_tetros **list)
{
	int	i;
	int min_y;

	i = 0;
	min_y = 4;
	while (i != 4)
	{
		if (((*list)->cell)[i].y < min_y)
			min_y = ((*list)->cell)[i].y;
		i++;
	}
	if (min_y > 0)
	{
		i = 0;
		while (i != 4)
		{
			((*list)->cell)[i].y -= min_y;
			i++;
		}
	}
}

static t_tetros	*lst_new(char *content, int number)
{
	int			i;
	int			j;
	t_tetros	*tmp;

	if (!(tmp = malloc(sizeof(t_tetros))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i != 4)
	{
		while (*(content + j) != 35 && *(content + j) != 0)
			j++;
		tmp->cell[i].x = j % 5;
		tmp->cell[i].y = j / 5;
		j++;
	}
	find_min_x(&tmp);
	find_min_y(&tmp);
	tmp->position = -1;
	tmp->count = number;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_tetros		*write_lst(char *str, int i)
{
	int			buf;
	int			number;
	t_tetros	*temp;
	t_tetros	*tmp;

	number = i;
	buf = 0;
	tmp = NULL;
	while (number != 0)
	{
		if (!(temp = lst_new(&*(str + buf), buf / 21 + 1)))
		{
			free(tmp);
			return (NULL);
		}
		lst_add_last(&tmp, temp);
		number--;
		buf += 21;
	}
	return (tmp);
}
