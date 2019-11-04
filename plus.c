/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:24:47 by medesmon          #+#    #+#             */
/*   Updated: 2019/04/11 20:31:02 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tetro.h"

int		counter(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) != 10 && *(str + i) != 32 && *(str + i) != 46)
			count++;
		i++;
	}
	count /= 4;
	return (count);
}

char	*empty_map(int power)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (power * (power + 1) + 1))))
		return (NULL);
	while (i != power * (power + 1))
	{
		if (i != 0 && (i + 1) % (power + 1) == 0)
			str[i] = 10;
		else
			str[i] = 46;
		i++;
	}
	*(str + i) = 0;
	return (str);
}

char	*clear_tetramin(char *str, int number)
{
	int	i;

	i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) >= number)
			*(str + i) = 46;
		i++;
	}
	return (str);
}

int		kostya(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((((i + 1) % 21) % 5 == 0) && (str[i] != 10))
			return (0);
		i++;
	}
	return (1);
}

char	*reading_map(char *filename)
{
	int		fd;
	char	*buffer;
	char	*buffer_buffer;
	char	*str;

	if (!(str = ft_strnew(0)))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (NULL);
	while (read(fd, buffer, BUFF_SIZE) > 0)
	{
		if (!(buffer_buffer = ft_strdup(str)))
			return (NULL);
		free(str);
		str = ft_strjoin(buffer_buffer, buffer);
		free(buffer_buffer);
		ft_bzero(buffer, BUFF_SIZE);
	}
	free(buffer);
	close(fd);
	return (str);
}
