/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:05:43 by cammapou          #+#    #+#             */
/*   Updated: 2017/12/28 15:29:11 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_modify_list(t_tetri *tetri, t_coord *c)
{
	int		i;
	int		j;
	int		tmp;

	tmp = c->j;
	i = 0;
	while (tetri->content[i])
	{
		j = 0;
		if (tetri->content[c->i])
		{
			if (tetri->content[i][j])
			{
				c->j = tmp;
				while (tetri->content[c->i][c->j])
					tetri->content[i][j++] = tetri->content[c->i][c->j++];
				while (tetri->content[i][j])
					tetri->content[i][j++] = '.';
			}
			c->i++;
		}
		while (tetri->content[i][j])
			tetri->content[i][j++] = '.';
		i++;
	}
}

void		ft_modif(t_tetri *tetri)
{
	t_tetri *tmp2;
	t_coord	*c;

	tmp2 = tetri;
	while (tmp2)
	{
		c = ft_return_min_motif(tmp2);
		ft_modify_list(tmp2, c);
		tmp2 = tmp2->next;
	}
}

t_coord		*ft_return_min_motif(t_tetri *tetri)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 4;
	k = 3;
	l = 3;
	while (i >= 0 && i--)
	{
		j = 4;
		while (j >= 0 && j--)
		{
			if (tetri->content[i][j] != '.')
			{
				if (i < k)
					k = i;
				if (j < l)
					l = j;
			}
		}
	}
	return (ft_init_point(k, l));
}

void		ft_init_h_w_motif(t_tetri *tetri)
{
	int	i;
	int	j;

	while (tetri != NULL)
	{
		i = 0;
		j = 0;
		ft_return_min_square(tetri->content, &i, &j);
		tetri->height = i + 1;
		tetri->width = j + 1;
		tetri = tetri->next;
	}
}

void		ft_sharp_to_letter(t_tetri *tetri)
{
	int			i;
	int			j;

	j = 0;
	while (tetri != NULL)
	{
		i = 0;
		tetri->letter = 'A' + j;
		j++;
		tetri = tetri->next;
	}
}
