/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:27 by zakboudi          #+#    #+#             */
/*   Updated: 2017/12/03 17:02:30 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	char const	*s2;
	size_t		i;

	i = -1;
	s1 = (char *)dst;
	s2 = (char const *)src;
	if (s2 < s1)
		while ((int)(--len) >= 0)
			*(s1 + len) = *(s2 + len);
	else
		while (++i < len)
			*(s1 + i) = *(s2 + i);
	return (dst);
}
