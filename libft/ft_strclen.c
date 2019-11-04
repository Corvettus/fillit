/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:11:11 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/25 01:32:49 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	res;

	if (!s)
		return (0);
	res = 0;
	while ((char)s[res] != c && s[res] && res + 1 > res)
		res++;
	if (res + 1 < res)
		return (0);
	return (res);
}
