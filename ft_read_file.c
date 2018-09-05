/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:35:38 by cammapou          #+#    #+#             */
/*   Updated: 2018/01/04 12:04:50 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_tetri(char *str)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == '#')
			j++;
	if (j != 4)
		return (0);
	i = 0;
	while (str[i])
	{
		if ((i != 4 && i != 9 && i != 14 && i != 19 && i != 20) &&
				(str[i] != '.' && str[i] != '#'))
			return (0);
		if ((i == 4 && i == 9 && i == 14 && i == 19) && (str[i] != '\n'))
			return (0);
		if (i == 20 && str[i] != '\n' && str[i] != '\0')
			return (0);
		i++;
	}
	if ((i == 19 && str[i] != '\n'))
		return (0);
	return (1);
}

t_tetri		*ft_read_file(char **argv)
{
	int		fd;
	int		i;
	t_tetri	*tetri;

	i = 0;
	tetri = NULL;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (NULL);
	ft_read(fd, &tetri, &i);
	close(fd);
	if (i != 20)
		ft_error();
	return (tetri);
}

void		ft_read(int fd, t_tetri **tetri, int *i)
{
	char	buf[BUF_SIZE + 1];
	t_tetri	*tmp;

	ft_bzero(buf, BUF_SIZE);
	while (read(fd, buf, BUF_SIZE))
	{
		*i = 0;
		buf[BUF_SIZE] = '\0';
		if (ft_check_tetri(buf) && ft_connection(buf))
		{
			tmp = ft_new_list(ft_strsplit(buf, '\n'), (sizeof(char*) * 5));
			ft_add_list(tetri, tmp);
		}
		else
			ft_error();
		while (buf[*i])
			(*i)++;
		ft_bzero(buf, BUF_SIZE);
	}
}

void		reverse_list(t_tetri **list)
{
	t_tetri	*old_list;
	t_tetri	*new_list;
	t_tetri	*tmp;

	old_list = *list;
	new_list = NULL;
	while (old_list)
	{
		tmp = old_list->next;
		old_list->next = NULL;
		ft_add_list(&new_list, old_list);
		old_list = tmp;
	}
	*list = new_list;
}

int			main(int argc, char **argv)
{
	t_tetri	*list;
	t_map	*tab;

	if (argc != 2)
		ft_usage();
	list = ft_read_file(argv);
	if (ft_get_nb_tetri(list) > 26 || !list)
		ft_error();
	reverse_list(&list);
	ft_modif(list);
	ft_init_h_w_motif(list);
	ft_sharp_to_letter(list);
	tab = ft_resolve(list);
	ft_print_table(tab);
	return (0);
}
