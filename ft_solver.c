/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:01:45 by zakboudi          #+#    #+#             */
/*   Updated: 2018/01/04 16:09:19 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_resolve_array(t_map *map, t_tetri *tetri)
{
	int	i;
	int	j;

	if (tetri == NULL)
		return (1);
	i = 0;
	while (i < map->size - tetri->height + 1)
	{
		j = 0;
		while (j < map->size - tetri->width + 1)
		{
			if (ft_place(tetri, map, i, j))
			{
				if (ft_resolve_array(map, tetri->next))
					return (1);
				else
					ft_put_value(tetri, map, ft_init_point(i, j), '.');
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_map	*ft_resolve(t_tetri *tetri)
{
	t_map	*map;
	int		size;

	size = high_sqrt(ft_get_nb_tetri(tetri) * 4);
	map = ft_init_map(size);
	while (!(ft_resolve_array(map, tetri)))
	{
		size++;
		ft_delmap(&map);
		map = ft_init_map(size);
	}
	return (map);
}

void	ft_put_value(t_tetri *tetri, t_map *map, t_coord *coord, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetri->height)
	{
		j = 0;
		while (j < tetri->width)
		{
			if (tetri->content[i][j] == '#')
				map->map[coord->i + i][coord->j + j] = c;
			j++;
		}
		i++;
	}
	ft_delcoord(&coord);
}

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	ft_usage(void)
{
	write(1, "usage : fillit | inpout-file\n", 29);
	exit(0);
}
