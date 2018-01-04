/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:01:07 by zakboudi          #+#    #+#             */
/*   Updated: 2017/12/03 17:01:09 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*s1;
	const char		*s2;
	unsigned char	i;
	size_t			j;

	s1 = (char *)dst;
	s2 = (const char *)src;
	i = (unsigned char)c;
	j = 0;
	while (j < n)
	{
		s1[j] = s2[j];
		if ((unsigned char)s2[j] == i)
			return (&dst[j + 1]);
		j++;
	}
	return (NULL);
}
