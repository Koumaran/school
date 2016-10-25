/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:45:46 by jsivanes          #+#    #+#             */
/*   Updated: 2016/02/04 15:22:56 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef	struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
t_list		*ft_list_push_params(int ac, char **av);
t_list				*ft_create_elem(void *data);
void				sort(t_list **begin_list, int (*cmp)());
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_print(t_list *list);
int		ft_strcmp(char *s1, char *s2);
#endif
