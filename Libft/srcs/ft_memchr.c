/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:01:25 by zakboudi          #+#    #+#             */
/*   Updated: 2017/12/03 17:01:28 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*str;
	unsigned char	i;
	size_t			j;

	str = (const char *)s;
	i = (unsigned char)c;
	j = 0;
	while (j < n)
	{
		if ((unsigned char)str[j] == i)
			return ((void *)&s[j]);
		j++;
	}
	return (NULL);
}
