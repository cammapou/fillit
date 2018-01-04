/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:21:14 by zakboudi          #+#    #+#             */
/*   Updated: 2017/12/28 14:41:45 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_init_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->size = size;
	if (!map)
		ft_error();
	map->map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!(map->map))
		ft_error();
	while (i < size)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!(map->map[i]))
			ft_error();
		j = 0;
		while (j < size)
			map->map[i][j++] = '.';
		map->map[i++][j] = '\0';
	}
	map->map[i] = NULL;
	return (map);
}

int		ft_get_nb_tetri(t_tetri *tetri)
{
	int i;

	i = 0;
	while (tetri)
	{
		i++;
		tetri = tetri->next;
	}
	return (i);
}

int		ft_place(t_tetri *tetri, t_map *map, int i, int j)
{
	int k;
	int l;

	k = 0;
	while (k < tetri->height)
	{
		l = 0;
		while (l < tetri->width)
		{
			if (tetri->content[k][l] == '#' && map->map[i + k][j + l] != '.')
				return (0);
			l++;
		}
		k++;
	}
	ft_put_value(tetri, map, ft_init_point(i, j), tetri->letter);
	return (1);
}

int		high_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

void	ft_return_min_square(char **table, int *k, int *l)
{
	int i;
	int j;

	i = 0;
	while (table[i] != NULL)
	{
		j = 0;
		while (table[i][j] != '\0')
		{
			if (table[i][j] != '.')
			{
				if (i > *k)
					*k = i;
				if (j > *l)
					*l = j;
			}
			j++;
		}
		i++;
	}
}
