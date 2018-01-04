/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:11:25 by cammapou          #+#    #+#             */
/*   Updated: 2017/12/28 16:26:15 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./Libft/includes/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 21

typedef struct		s_tetri
{
	char			**content;
	char			letter;
	int				height;
	int				width;
	size_t			content_size;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_coord
{
	int				i;
	int				j;
}					t_coord;

typedef struct		s_map
{
	char			**map;
	int				size;
}					t_map;

char				**ft_read_fil(char **argv);
int					ft_connection(char *str);
t_tetri				*ft_tetri(char **str, size_t size);
void				ft_add_list(t_tetri **alst, t_tetri *new);
int					size_map(char **map);
char				**solve(t_tetri *first, char **tab, int nb_tetri);
t_tetri				*ft_new_list(void const *content, size_t content_size);
t_tetri				*new_tetri(char **tetri, int num);
void				ft_modify_list(t_tetri *tetri, t_coord *c);
t_coord				*ft_return_min_motif(t_tetri *tetri);
t_coord				*ft_init_point(int i, int j);
void				ft_init_h_w_motif(t_tetri *tetri);
void				ft_return_min_square(char **table, int *k, int *l);
t_map				*ft_init_map(int size);
char				**ft_resize_map(char **map);
void				ft_sharp_to_letter(t_tetri *tetri);
int					ft_get_nb_tetri(t_tetri *tetri);
void				ft_error(void);
void				ft_print_table(t_map *map);
void				ft_delmap(t_map **map);
void				ft_delcoord(t_coord **coord);
t_map				*ft_resolve(t_tetri *tetri);
void				ft_put_value(t_tetri *tetri, t_map *map,
		t_coord *corrd, char c);
int					ft_place(t_tetri *tetri, t_map *map, int i, int j);
int					high_sqrt(int n);
void				ft_modif(t_tetri *tetri);
void				ft_read(int fd, t_tetri **tetri, int *i);
void				ft_usage();

#endif
