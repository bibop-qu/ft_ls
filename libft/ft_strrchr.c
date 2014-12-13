/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:23:39 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/12 18:36:00 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char				*ft_strrchr(const char *s, int c)
{
	int i;

	i = (int)ft_strlen((char*)s);
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
			return ((char*)&s[i]);
		i--;
	}
	return (0);
}
