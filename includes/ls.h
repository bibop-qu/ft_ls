/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 14:34:52 by basle-qu          #+#    #+#             */
/*   Updated: 2014/12/13 11:47:38 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# define file struct dirent

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

char	*ft_getmod(int mod);
void	ft_ls(char *optn, char *chemin);

#endif
