/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:22:13 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/17 10:19:53 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (s[res] && res + 1 > res)
		res++;
	if (res + 1 < res)
		return (0);
	return (res);
}
