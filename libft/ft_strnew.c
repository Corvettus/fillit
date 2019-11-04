/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:07:00 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/17 10:20:57 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 < size)
		return (0);
	if (!(str = (char*)malloc((size + 1) * sizeof(char))))
		return (0);
	ft_bzero((void*)str, size + 1);
	return (str);
}
