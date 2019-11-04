/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:38:09 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/17 10:10:41 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst && del)
	{
		while (*alst)
		{
			tmp = *alst;
			(*del)((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
			free(tmp);
			tmp = 0;
		}
		free(*alst);
		*alst = 0;
	}
}
