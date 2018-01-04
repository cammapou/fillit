/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:04:33 by zakboudi          #+#    #+#             */
/*   Updated: 2018/01/04 11:54:08 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_connection(char *str)
{
	int		i;
	int		links;

	i = 0;
	links = 0;
	while (i < 19)
	{
		if (str[i] == '#')
		{
			if (str[i - 5] == '#')
				links++;
			if (str[i + 5] == '#')
				links++;
			if (str[i - 1] == '#')
				links++;
			if (str[i + 1] == '#')
				links++;
		}
		i++;
	}
	if (links != 6 && links != 8)
		return (0);
	return (1);
}

t_tetri		*ft_new_list(void const *content, size_t content_size)
{
	t_tetri	*list;

	list = (t_tetri *)malloc(sizeof(t_tetri));
	if (!list)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = malloc(content_size);
		if (!list->content)
		{
			free(list);
			return (NULL);
		}
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}

void		ft_add_list(t_tetri **alst, t_tetri *new)
{
	if (*alst != NULL)
		new->next = *alst;
	*alst = new;
}
