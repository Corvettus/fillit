/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 03:19:39 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/17 10:08:37 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126 ? 1 : 0);
}