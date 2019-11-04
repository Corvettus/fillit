/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:11:43 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/22 16:31:11 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = (ft_strlen(src) < n ? ft_strlen(src) : n);
	if (len + 1 < len)
		return (0);
	if (!(res = (char*)malloc(len + 1)))
		return (0);
	i = 0;
	while (src[i] && i < n)
	{
		res[i] = (char)src[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
