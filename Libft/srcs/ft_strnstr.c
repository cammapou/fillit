/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:17:23 by zakboudi          #+#    #+#             */
/*   Updated: 2017/12/03 17:17:25 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		k = i;
		j = 0;
		while (haystack[i] == needle[j] && i < len)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[k]);
		}
		k++;
		i = k;
	}
	return (NULL);
}
