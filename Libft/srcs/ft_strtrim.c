/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakboudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:18:55 by zakboudi          #+#    #+#             */
/*   Updated: 2017/12/03 17:18:57 by zakboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = i;
	while (s[i + 1] != '\0')
		i++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	k = i;
	str = (char *)malloc(sizeof(char) * ((k - j) + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (j < (k + 1))
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}
