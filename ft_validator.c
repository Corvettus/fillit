/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:24:19 by medesmon          #+#    #+#             */
/*   Updated: 2019/04/11 20:31:21 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetro.h"

static int		ld_tetr(char *str, int i, int c)
{
	static int	count;

	count = c;
	if (i > 0 && *(str + i - 1) == 35)
	{
		ld_tetr(str, i - 1, count);
		count++;
	}
	if (i < (int)ft_strlen(str) - 5 && *(str + i + 5) == 35 \
		&& i + 5 < 21 * (i / 21 + 1) - 1)
	{
		ld_tetr(str, i + 5, count);
		count++;
	}
	if (count == 4)
	{
		count = 1;
		return (4);
	}
	return (count);
}

static int		dr_tetr(char *str, int i, int c)
{
	static int	count;

	count = c;
	if (i < (int)ft_strlen(str) && *(str + i + 1) == 35)
	{
		dr_tetr(str, i + 1, count);
		count++;
	}
	if (i < (int)ft_strlen(str) - 5 && *(str + i + 5) == 35 \
		&& i + 5 < 21 * (i / 21 + 1) - 1)
	{
		dr_tetr(str, i + 5, count);
		count++;
	}
	if (count == 4)
	{
		count = 1;
		return (4);
	}
	return (count);
}

static int		tetramin(int i, char *str)
{
	int	max;
	int	count;

	if ((count = dr_tetr(str, i, 1)) == 4)
		return (count);
	else if ((count = ld_tetr(str, i, 1)) == 4)
		return (count);
	max = 21 * (i / 21 + 1) - 1;
	if (i + 6 <= (int)ft_strlen(str) && i + 6 < max && *(str + i + 1) == 35 \
		&& *(str + i + 5) == 35 && *(str + i + 6) == 35)
		return (4);
	if (i + 6 <= (int)ft_strlen(str) && i + 6 < max && *(str + i + 4) == 35 \
		&& *(str + i + 5) == 35 && *(str + i + 6) == 35)
		return (4);
	if (i + 5 <= (int)ft_strlen(str) && i + 5 < max && *(str + i + 1) == 35 \
		&& *(str + i + 4) == 35 && *(str + i + 5) == 35)
		return (4);
	while (*(str + i) != 35 && *(str + i) != 0 && i != max)
		i++;
	return (count);
}

static int		valid(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 4;
	while (*(str + i) != 0)
	{
		if (count != 4 && ((i + 2) % 21 == 0))
			return (0);
		else if (count == 4 && (i % 21 == 0))
			count = 0;
		if ((*(str + i) != 46) && (*(str + i) != 35) && (*(str + i) != 10))
			return (0);
		if (*(str + i) == 10 && (((i + 1) % 21) % 5 != 0 && (i % 21) % 20 != 0))
			return (0);
		if (*(str + i) == 35 && count == 0 && tetramin(i, str) != 4)
			return (0);
		if (*(str + i) == 35)
			count++;
		i++;
	}
	if (*str == 10 || *str == 0 || (i > 1 && str[i - 1] == 10 && \
		str[i - 2] == 10) || (i + 1) % 21 != 0)
		return (0);
	return (i / 21 + 1);
}

int				ft_validator(char *filename, t_tetros **ft_figset)
{
	int		count;
	char	*str;

	str = reading_map(filename);
	if (!(kostya(str)))
		return (0);
	if ((count = valid(str)) && count <= LIMIT)
	{
		*ft_figset = write_lst(str, count);
		free(str);
		return (count);
	}
	free(str);
	return (0);
}
