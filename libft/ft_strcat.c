/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:30:01 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/17 10:18:15 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*temp;

	temp = s1;
	while (*temp)
		temp++;
	while (*s2)
		*(temp++) = *(s2++);
	*temp = 0;
	return (s1);
}
