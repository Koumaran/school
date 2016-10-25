/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 18:38:44 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/22 19:15:19 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"

typedef	struct		s_struct
{
	int				cube;
	char			**map;
	char			**tetris;
}					t_struct;

void	ft_tetris(char *file);
char	**init_map(char *s, int j, int cube);
char	**ft_create_tet(int cube);
char	*ft_push_top(char *map, char letter, int i, int y);
char	**ft_fillit(t_struct *box, char **map, int x, int y);

#endif
