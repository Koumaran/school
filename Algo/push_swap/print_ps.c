/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 11:47:12 by jsivanes          #+#    #+#             */
/*   Updated: 2016/11/09 16:10:38 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		join_ss_rr_rrr(char **str, char *dest, char *src)
{
	if ((!CMP(dest, "=sa\0") && !CMP(src, "=sb\0")) ||
			(!CMP(dest, "=sb\0") && !CMP(src, "=sa\0")))
	{
		*str = JN(*str, DP("=ss"));
		return (1);
	}
	if ((!CMP(dest, "=ra\0") && !CMP(src, "=rb\0")) ||
			(!CMP(dest, "=rb\0") && !CMP(src, "=ra\0")))
	{
		*str = JN(*str, DP("=rr"));
		return (1);
	}
	if ((!CMP(dest, "=rra\0") && !CMP(src, "=rrb\0")) ||
			(!CMP(dest, "=rrb\0") && !CMP(src, "=rra\0")))
	{
		*str = JN(*str, DP("=rrr"));
		return (1);
	}
	return (0);
}

char			*print_join(char **tab, int len)
{
	int		i;
	char	*str;
	int		x;

	len = (int)ft_strtablen(tab);
	i = -1;
	str = ft_strnew(0);
	while (++i < len)
	{
		x = 0;
		if (i + 1 < len && (x = join_ss_rr_rrr(&str, tab[i], tab[i + 1])) == 1)
		{
			ft_strdel(&tab[i++]);
			ft_strdel(&tab[i]);
		}
		else if (x == 0)
			str = JN(str, tab[i]);
	}
	free(tab);
	return (str);
}

void			print_ps(char **tab, int c, int w)
{
	int		len;
	int		i;

	i = -1;
	len = ft_strtablen(tab);
	while (++i < len)
	{
		if (c && i + 1 == len)
			ft_printf("\033[33m%s\n\033[0m", tab[i]);
		else
			ft_printf("%s\n", tab[i]);
	}
	if (w)
		ft_printf("Total: %d operation(s).\n", len);
	ft_memfree_2d(tab);
}

void			print_v(char **tab, int c, int w)
{
	int		len;
	int		y;

	len = ft_strtablen(tab);
	y = -1;
	while (++y < len)
	{
		if (y + 1 == len && c)
			ft_printf("\033[33m%s\033[0m", tab[y]);
		else
			ft_putstr(tab[y]);
	}
	if (w)
		ft_printf("Total: %d operation(s).\n", len);
	ft_memfree_2d(tab);
}
