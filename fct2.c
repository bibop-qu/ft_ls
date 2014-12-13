/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:51:56 by basle-qu          #+#    #+#             */
/*   Updated: 2014/12/13 10:30:04 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ls.h"

void	ft_init_optn(char *optn, int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	ft_bzero(optn, 5);
	while (j < ac && av[j][0] == '-')
	{
		i = 0;
		while (ac > 1 && av[j][i] != '\0' && av[j][0] == '-')
		{
			if (av[j][i] == 'l')
				optn[0] = 'l';
			if (av[j][i] == 'R')
				optn[1] = 'R';
			if (av[j][i] == 'a')
				optn[2] = 'a';
			if (av[j][i] == 'r')
				optn[3] = 'r';
			if (av[j][i] == 't')
				optn[4] = 't';
			i++;
		}
		j++;
	}
}

char	**ft_sort_arg(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		if (av[j] != '\0' && av[i][0] != '-' && ft_strcmp(av[i], av[j]) >= 0)
		{
			tmp = av[i];
			av[i] = av[j];
			av[j] = tmp;
		}
		i++;
	}
	return (av);
}

void	make_ls(int ac, char **av, char *optn)
{
	int		i;
	char	*chemin;

	i = 1;
	while (av[i] && av[i][0] == '-')
		i++;
	if (!av[i])
		ft_ls(optn, ".");
	while (i < ac)
	{
		chemin = av[i];
		if (ac < 2 || (av[i - 1][0] == '-' && !av[i + 1]))
			;
		else
		{
			ft_putstr(chemin);
			ft_putchar(':');
			ft_putchar('\n');
		}
		ft_ls(optn, chemin);
		if (ac > 2 && (i + 1) < ac)
			ft_putchar('\n');
		i++;
	}
}
