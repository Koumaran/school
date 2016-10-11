/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <maxpetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 12:25:09 by maxpetit          #+#    #+#             */
/*   Updated: 2016/02/07 18:10:50 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			free_tab_err(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static	void	init_tab_err_1(char **tab)
{
	tab[0] = (char*)ft_strdump("Succes\n");
	tab[1] = ft_strdump("Operation not permitted\n");
	tab[2] = ft_strdump("No such file or directory\n");
	tab[3] = ft_strdump("No such process\n");
	tab[4] = ft_strdump("Interrupted system call\n");
	tab[5] = ft_strdump("I/O error\n");
	tab[6] = ft_strdump("No such device or address\n");
	tab[7] = ft_strdump("Argument list too long\n");
	tab[8] = ft_strdump("Exec format error\n");
	tab[9] = ft_strdump("Bad file number\n");
	tab[10] = ft_strdump("No child processes\n");
	tab[11] = ft_strdump("Try again\n");
	tab[12] = ft_strdump("Out of memory\n");
	tab[13] = ft_strdump("Permission denied\n");
	tab[14] = ft_strdump("Bad address\n");
	tab[15] = ft_strdump("Block device required\n");
	tab[16] = ft_strdump("Device or resource busy\n");
	tab[17] = ft_strdump("File exists\n");
	tab[18] = ft_strdump("Cross-device link\n");
	tab[19] = ft_strdump("No such device\n");
	tab[20] = ft_strdump("Not a directory\n");
	tab[21] = ft_strdump("Is a directory\n");
	tab[22] = ft_strdump("Invalid argument\n");
	tab[23] = ft_strdump("File table overflow\n");
	tab[24] = ft_strdump("Too many open files\n");
}

static	void	init_tab_err_2(char **tab)
{
	tab[25] = ft_strdump("Not a typewriter\n");
	tab[26] = ft_strdump("Text file busy\n");
	tab[27] = ft_strdump("File too large\n");
	tab[28] = ft_strdump("No space left on device\n");
	tab[29] = ft_strdump("Illegal seek\n");
	tab[30] = ft_strdump("Read-only file system\n");
	tab[31] = ft_strdump("Too many links\n");
	tab[32] = ft_strdump("Broken pipe\n");
	tab[33] = ft_strdump("Math argument out of domain of func\n");
	tab[34] = ft_strdump("Math result not representable\n");
	tab[35] = NULL;
}

char			**init_tab_err(void)
{
	char	**tab_err;

	tab_err = (char**)malloc((sizeof(char*) + 1) * 35);
	init_tab_err_1(tab_err);
	init_tab_err_2(tab_err);
	return (tab_err);
}
