/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:15:38 by tlynesse          #+#    #+#             */
/*   Updated: 2019/01/17 10:11:10 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	if (!f)
		return (0);
	res = 0;
	while (lst)
	{
		if (!(tmp = (t_list*)malloc(sizeof(t_list))))
			return (ft_free_lst_mem(&res));
		tmp = (*f)(lst);
		if (!tmp)
			return (ft_free_lst_mem(&res));
		ft_lstaddback(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
