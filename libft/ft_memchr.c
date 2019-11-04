/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 07:57:05 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/17 10:11:36 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	ps = (unsigned char*)s;
	i = 0;
	while (i < n && ps[i] != (unsigned char)c)
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((void*)&s[i]);
}
