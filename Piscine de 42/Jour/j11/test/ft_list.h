/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:43:50 by jsivanes          #+#    #+#             */
/*   Updated: 2016/05/17 14:49:57 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef	struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list				*ft_list_push_params(int ac, char **av);
int					ft_strcmp(char const *s1, char const *s2);
t_list				*ft_create_elem(void *data);
void				ft_print(t_list *list);
void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_list_remove_if(t_list **begin_list,\
					void *data_ref, int (*cmp)());
#endif
