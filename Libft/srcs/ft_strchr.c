/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:07:42 by zakboudi          #+#    #+#             */
/*   Updated: 2017/12/03 17:07:44 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	l;
	int		i;

	l = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == l)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] != l)
		return (NULL);
	else
		return ((char *)&s[i]);
}
