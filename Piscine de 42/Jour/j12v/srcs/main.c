/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:25:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/24 15:29:24 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_manage_print(int ac, char **av, char **tab_error, int i)
{
	int		fd;

	if (ac == 3)
		ft_print_file(0);
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY, S_IREAD);
		if (fd == -1)
			ft_puterror(av[0], av[i], tab_error[errno]);
		else
		{
			if (ac > 4)
			{
				if (i != 3 && !errno)
					write(1, "\n", 1);
				write(1, "==> ", 4);
				write(1, av[i], ft_strlen(av[i]));
				write(1, " <==\n", 5);
				errno = 0;
			}
			ft_print_file(fd);
			close(fd);
		}
		i++;
	}
}

static	void	ft_error_offest(char *prg_name, char *offset)
{
	write(2, prg_name, ft_strlen(prg_name));
	write(2, ": illegal offset -- ", 20);
	write(2, offset, ft_strlen(offset));
	write(2, "\n", 1);
}

int				main(int ac, char **av)
{
	char	**tab_error;

	if (ac == 1 || ((ac >= 2) && (av[1][0] != '-'
					|| av[1][1] != 'c' || av[1][2] != '\0')))
	{
		ft_puterror(av[0], 0, "option requires an argument - - 'c'\n");
		return (0);
	}
	if (ac >= 3)
	{
		ft_atoi_verif(av[2]);
		if (get_set_nbchar(GET_STATUS, 0) == WRONG_NUMBER)
		{
			ft_error_offest(av[0], av[2]);
			return (0);
		}
		tab_error = init_tab_err();
		ft_manage_print(ac, av, tab_error, 3);
		free_tab_err(tab_error);
	}
	return (0);
}
