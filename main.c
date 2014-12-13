/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 14:48:29 by basle-qu          #+#    #+#             */
/*   Updated: 2014/12/13 09:59:35 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ls.h"
#include "list.h"
#include "fct.h"
#include "fct2.h"


char	ft_gettype(int mod)
{
	char c;

	if (S_ISDIR(mod) == 1)
		c = 'd';
	else if (S_ISLNK(mod) == 1)
		c = 'l';
	else if (S_ISFIFO(mod) == 1)
		c = 'p';
	else if (S_ISBLK(mod) == 1)
		c = 'b';
	else if (S_ISCHR(mod) == 1)
		c = 'c';
	else if (S_ISSOCK(mod) == 1)
		c = 's';
	else
		c = '-';
	return (c);
}

char	*ft_getmod(int mod)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 10 + 1);
	str[0] = ft_gettype(mod);
	str[1] = 00400 & mod ? 'r' : '-';
	str[2] = 00200 & mod ? 'w' : '-';
	str[3] = 00100 & mod ? 'x' : '-';
	str[4] = 00040 & mod ? 'r' : '-';
	str[5] = 00020 & mod ? 'w' : '-';
	str[6] = 00010 & mod ? 'x' : '-';
	str[7] = 00004 & mod ? 'r' : '-';
	str[8] = 00002 & mod ? 'w' : '-';
	str[9] = 00001 & mod ? 'x' : '-';
	str[10] = 0;
	return (str);
}

void	ft_print_list(t_list *list, char *optn)
{
	t_list	*tmp;
	int		*max_var;

	tmp = list;
	max_var = (int*)malloc(sizeof(int) * 4);
	init_max_var(list, max_var);
	if (optn[0] =='l')
		ft_print_total(list);
	while (tmp != NULL && optn[2] == 'a')
	{
		if (optn[0] == 'l')
			print_optn(tmp, max_var);	
		ft_putendl(tmp->nom);
		tmp = tmp->next;
	}
	while (tmp != NULL && optn[2] != 'a')
	{
		if (tmp->nom[0] != '.')
		{
			if (optn[0] == 'l')
 				print_optn(tmp, max_var);
			ft_putendl(tmp->nom);
		}
		tmp = tmp->next;
	}
}

void	ft_ls(char *optn, char *chemin)
{
	DIR		*rep;
	file	*fichierlu;
	t_list	*list;

	list = NULL;
	rep = opendir(chemin);
	if (!rep) perror("");
	while ((fichierlu = readdir(rep)) != NULL)
		list = add_link(list, fichierlu, chemin);
	ft_sort_list(&list, optn);
	if (optn[3] == 'r')
		ft_reverse_list(&list);
	ft_print_list(list, optn);
}

int		main(int ac, char **av)
{
	char	optn[5];

	ft_init_optn(optn, ac, av);
	ft_sort_arg(ac, av);
	make_ls(ac, av, optn);
	return (0);
}
