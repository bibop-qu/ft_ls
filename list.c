/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 16:33:49 by basle-qu          #+#    #+#             */
/*   Updated: 2014/12/13 10:03:46 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "ls.h"
#include "list.h"

void	ft_reverse_list(t_list **list)
{
	t_list	*new_begin;
	t_list	*prev;
	t_list	*next;

	new_begin = *list;
	while (new_begin->next)
		new_begin = new_begin->next;
	next = new_begin;
	while (next != *list)
	{
		prev = *list;
		while (prev->next != next)
			prev = prev->next;
		next->next = prev;
		next = prev;
	}
	next->next = NULL;
	*list = new_begin;
}

void	ft_swap_list(t_list **list, t_list *tmp)
{
	t_list	*avant;
	t_list	*apres;

	if (tmp == *list)
	{
		apres = tmp->next;
		tmp->next = tmp->next->next;
		apres->next = tmp;
		*list = apres;
	}
	else
	{
		avant = *list;
		apres = tmp->next;
		while (avant->next != tmp)
			avant = avant->next;
		avant->next = apres;
		tmp->next = apres->next;
		apres->next = tmp;
	}
}

void	ft_sort_list(t_list **list, char *optn)
{
	int		i;
	t_list	*tmp;

	i = 1;
	while (i)
	{
		i = 0;
		tmp = *list;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->nom, tmp->next->nom) > 0 && optn[4] != 't')
			{
				i = 1;
				ft_swap_list(list, tmp);
			}
			else if (tmp->time < tmp->next->time && optn[4] == 't')
			{
				i = 1;
				ft_swap_list(list, tmp);
			}
			else
				tmp = tmp->next;
		}
	}
}

char	*tri_join(char *chemin, char  *d_name)
{
	char	*cpy;
	char	*cpy2;

	cpy = ft_strjoin(chemin, "/");
	cpy2 = ft_strjoin(cpy, d_name);
	free(cpy);
	return (cpy2);
}

t_list	*init_new(t_list *new, file *fichierlu, char *chemin)
{
	int				i;
	struct stat		v_stat;
	struct group	*v_group;
	struct passwd	*v_passwd;

	i = stat(tri_join(chemin, fichierlu->d_name), &v_stat);
	if (i == -1)
		perror("");
	new->size = v_stat.st_size;
	new->time = v_stat.st_mtime;
	new->link = v_stat.st_nlink;
	new->permission = v_stat.st_mode;
	new->blk = v_stat.st_blocks;
	v_group = getgrgid(v_stat.st_gid);
	v_passwd = getpwuid(v_stat.st_uid);
	new->nom_group = v_group->gr_name;
	new->nom_user = v_passwd->pw_name;
	i = -1;
	while (++i < 256)
		new->nom[i] = fichierlu->d_name[i];
	new->next = NULL;
	return (new);
}

t_list		*add_link(t_list *list, file *fichierlu, char *chemin)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(t_list));
	new = init_new(new, fichierlu, chemin);
	tmp = list;
	if (list == NULL && new->nom[0])
		return (new);
	while (tmp->next != NULL && new->nom[0])
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
