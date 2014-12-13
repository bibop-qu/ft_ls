/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 20:47:16 by basle-qu          #+#    #+#             */
/*   Updated: 2014/12/13 11:30:16 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "list.h"
#include "libft/includes/libft.h"

void	ft_n_space(int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

int		size_int(int n)
{
	int		i;
	int		size;

	i = 0;
	size = 1;
	while (size <= n)
	{
		i++;
		size *= 10;
	}
	return (i);
}

void	init_max_var(t_list *list, int *max_var)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = list;
	while (i < 4)
	{
		max_var[i] = 0;
		i++;
	}
	while (tmp != NULL)
	{
		if (tmp->link > max_var[0])
			max_var[0] = size_int(tmp->link);
		if ((int)ft_strlen(tmp->nom_user) > max_var[1])
			max_var[1] = ft_strlen(tmp->nom_user);
		if ((int)ft_strlen(tmp->nom_group) > max_var[2])
			max_var[2] = ft_strlen(tmp->nom_group);
		if (size_int((int)tmp->size) > max_var[3])
			max_var[3] = size_int((int)tmp->size);
		tmp = tmp->next;
	}
}

void	ft_print_total(t_list *list)
{
	int		total;
	t_list	*tmp;

	tmp = list;
	total = 0;
	while (tmp != NULL)
	{
		total += tmp->blk;
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}

void	print_optn(t_list *tmp, int *max_var)
{
	ft_putstr(ft_getmod(tmp->permission));
	ft_n_space((max_var[0] - size_int(tmp->link)) + 2);
	ft_putnbr((int)tmp->link);
	ft_putchar(' ');
	ft_putstr(tmp->nom_user);
	ft_n_space((max_var[1] - ft_strlen(tmp->nom_user)) + 2);
	ft_putstr(tmp->nom_group);
	ft_n_space((max_var[2] - ft_strlen(tmp->nom_group)) + 2);
	ft_n_space(max_var[3] - size_int(tmp->size));
	ft_putnbr((int)tmp->size);
	ft_putchar(' ');
	ft_putstr(ft_strsub(ctime((const time_t*)&tmp->time), 4, 12));
	ft_putchar(' ');
}
