/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:09:45 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/17 10:13:09 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putlst(t_list *lst)
{
	if (lst)
		while (lst->content)
		{
			ft_putstr((char const*)lst->content);
			lst = lst->next;
		}
}
