/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:53:50 by basle-qu          #+#    #+#             */
/*   Updated: 2014/12/09 10:52:35 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT2_H
# define FCT2_H

void	ft_init_optn(char *optn , int ac, char **av);
void	make_ls(int ac, char **av, char *optn);
char	**ft_sort_arg(int ac, char **av);

#endif
