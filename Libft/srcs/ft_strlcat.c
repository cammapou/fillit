/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:14:14 by zakboudi          #+#    #+#             */
/*   Updated: 2017/12/03 17:14:15 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)ft_memchr(dst, '\0', size);
	if (!s1)
		return (size + ft_strlen(src));
	s2 = (char *)src;
	i = (size_t)(s1 - dst) + ft_strlen(s2);
	while ((size_t)(s1 - dst) < size - 1 && *s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (i);
}
