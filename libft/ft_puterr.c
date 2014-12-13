/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 16:17:03 by basle-qu          #+#    #+#             */
/*   Updated: 2014/11/21 16:18:29 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_puterr(char *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	write(2, "\n", 1);
}
