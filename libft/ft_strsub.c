/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:58:59 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/18 10:29:38 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cpy;

	if (s == 0)
		return (0);
	i = 0;
	cpy = (char*)malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		cpy[i] = s[start];
		start++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
