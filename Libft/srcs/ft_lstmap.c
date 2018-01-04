/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:00:29 by zakboudi          #+#    #+#             */
/*   Updated: 2017/12/03 17:00:32 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *map, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!map)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (map != NULL)
		new = f(map);
	new->next = ft_lstmap(map->next, f);
	return (new);
}
