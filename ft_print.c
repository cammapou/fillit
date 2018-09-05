/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 11:23:18 by cammapou          #+#    #+#             */
/*   Updated: 2017/12/28 14:42:25 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_table(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
		ft_putendl(map->map[i++]);
}

void	ft_delmap(t_map **map)
{
	int	i;

	i = 0;
	while ((*map)->map[i] != NULL)
	{
		free((*map)->map[i]);
		(*map)->map[i] = NULL;
		i++;
	}
	free((*map)->map);
	(*map)->map = NULL;
	free(*map);
	*map = NULL;
}

t_coord	*ft_init_point(int i, int j)
{
	t_coord	*point;

	point = (t_coord *)malloc(sizeof(t_coord));
	if (!point)
		ft_error();
	point->i = i;
	point->j = j;
	return (point);
}

void	ft_delcoord(t_coord **coord)
{
	free(*coord);
	*coord = NULL;
}
