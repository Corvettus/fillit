/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:23:58 by medesmon          #+#    #+#             */
/*   Updated: 2019/04/11 20:30:31 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetro.h"

static int	fill_could(t_tetros *list, char *str, int pow, int i)
{
	int	count;

	count = 0;
	if (!(i + list->cell[3].x + (pow + 1) * list->cell[3].y < pow * (pow + 1)))
		return (0);
	if (!(i % (pow + 1) + list->cell[0].x < pow && i % (pow + 1) + \
		list->cell[1].x < pow && i % (pow + 1) + list->cell[2].x < pow && \
		i % (pow + 1) + list->cell[3].x < pow))
		return (0);
	if (*(str + i + list->cell[0].x + (pow + 1) * list->cell[0].y) == 46)
		count++;
	if (*(str + i + list->cell[1].x + (pow + 1) * list->cell[1].y) == 46)
		count++;
	if (*(str + i + list->cell[2].x + (pow + 1) * list->cell[2].y) == 46)
		count++;
	if (*(str + i + list->cell[3].x + (pow + 1) * list->cell[3].y) == 46)
		count++;
	if (count == 4)
		return (1);
	else
		return (0);
}

static void	fill_it(t_tetros *list, char **str, int pow, int i)
{
	int	letter;

	letter = list->count;
	*(*str + i + list->cell[0].x + (pow + 1) * list->cell[0].y) = letter + 64;
	*(*str + i + list->cell[1].x + (pow + 1) * list->cell[1].y) = letter + 64;
	*(*str + i + list->cell[2].x + (pow + 1) * list->cell[2].y) = letter + 64;
	*(*str + i + list->cell[3].x + (pow + 1) * list->cell[3].y) = letter + 64;
}

static int	fill_help(t_tetros **list, char **str, int count)
{
	if (count == 1)
	{
		if ((*list)->next)
			(*list) = (*list)->next;
	}
	else
	{
		if ((*list)->prev)
		{
			(*list)->position = -1;
			(*list) = (*list)->prev;
		}
		else
		{
			(*list)->position = -1;
			return (-1);
		}
		clear_tetramin(*str, (*list)->count + 64);
	}
	return (0);
}

static char	*fill(t_tetros **list, char *str, int power, int number)
{
	int i;
	int	count;

	while (counter(str) != number)
	{
		i = 0;
		count = 0;
		while (i <= (*list)->position)
			i++;
		while (i < (power + 1) * power && count != 1)
		{
			if (fill_could(*list, str, power, i))
			{
				fill_it(*list, &str, power, i);
				(*list)->position = i;
				count++;
			}
			i++;
		}
		if ((fill_help(&*list, &str, count) == -1))
			break ;
	}
	return (str);
}

void		ft_fill(t_tetros *list, int numbers)
{
	int		i;
	int		power;
	char	*str;

	power = 0;
	while (power * power < numbers)
		power++;
	i = 0;
	str = ft_strnew(0);
	while (counter(str) != numbers / 4)
	{
		free(str);
		str = empty_map(power + i);
		str = fill(&list, str, power + i, numbers / 4);
		i++;
	}
	ft_putstr(str);
	while (list->count != 1)
	{
		list = list->prev;
		free(list->next);
	}
	free(list);
	free(str);
}
