/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:52:34 by jsivanes          #+#    #+#             */
/*   Updated: 2016/02/04 14:20:35 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef	struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
t_list		*ft_create_elem(void *data);
t_list		*ft_list_push_params(int ac, char **av);
void		ft_putstr(char *str);
void		ft_putchar(char c);
int			ft_strcmp(char *s1, char *S2);
void				ft_list_add(t_list **begin_list,\
					t_list *begin_list2, int (*cmp)());
void				sort(t_list **list, int (*cmp)());
#endif
