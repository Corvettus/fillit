/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 06:21:19 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/21 20:45:19 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	buf;
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	buf = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = 0;
	return (res);
}
