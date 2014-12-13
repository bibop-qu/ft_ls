/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 16:38:47 by basle-qu          #+#    #+#             */
/*   Updated: 2014/12/13 10:02:44 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <stdio.h>
#include <errno.h>

typedef struct	s_list
{
	char			nom[256];
	time_t			time;
	off_t			size;
	char			*nom_group;
	char			*nom_user;
	nlink_t			link;
	mode_t			permission;
	blkcnt_t		blk;
	struct s_list	*next;
}				t_list;

void	ft_reverse_list(t_list **list);
void	ft_swap_list(t_list **list, t_list *tmp);
void	ft_sort_list(t_list **list, char *optn);
t_list	*add_link(t_list *list, struct dirent *fichierlu, char * chemin);

#endif
