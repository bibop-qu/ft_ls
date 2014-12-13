/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:52:22 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/10 18:38:05 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static size_t		ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	i = 0;
	ptrdst = dst;
	ptrsrc = src;
	if (len <= ft_strlen(dst))
	{
		ptrdst[i] = ptrsrc[i];
		i++;
		len--;
	}
	else
	{
		dst = (char*)malloc(sizeof(char) * len + 1);
		while (len)
		{
			ptrdst[i] = ptrsrc[i];
			i++;
			len--;
		}
	}
	return (dst);
}

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned int			dstlen;
	unsigned char			*ptrdst;
	const unsigned char		*ptrsrc;

	i = 0;
	dstlen = (unsigned int)ft_strlen(dst);
	ptrdst = dst;
	ptrsrc = src;
	if (n <= dstlen)
	{
		while (n > 0)
		{
			ptrdst[i] = ptrsrc[i];
			i++;
			n--;
		}
	}
	else
		ft_memmove(dst, src, n);
	return (dst);
}
