/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:40 by zakboudi          #+#    #+#             */
/*   Updated: 2017/12/03 17:02:43 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	unsigned char	l;
	size_t			i;

	str = (char *)b;
	l = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = l;
		i++;
	}
	return (b);
}
