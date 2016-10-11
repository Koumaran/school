/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:06:56 by jsivanes          #+#    #+#             */
/*   Updated: 2016/04/22 20:15:11 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*str = "*salut*les***etudiants*\0";
	t_list	*res;
	char	*dst = ft_strnew(1);
//	int		fd = -1;
//	char	dst[50] = "j'aime les bonbons\n\0";

//	ft_putstr(str);
//	ft_memset(str, '$', 5);
//	ft_putstr(str);
//	ft_bzero(str, 5);
//	ft_putstr(ft_memcpy(dst, str, 5));
//	res = ft_memchr(str, 'i', 6);
//	i = ft_memcmp(str, dst, 10);
//	i = ft_strlen(str);	
	ft_putstr(ft_strdup("salut les copins\n"));
//	res = ft_strncpy(dst, str, 5);
//	res = ft_strcat(dst, str);
//	res = ft_strncat(dst, str, 5);
//	ft_putnbr(ft_strlcat(dst, str, 36));
//	ft_putstr(ft_strchr(str, '\0'));
//	ft_putstr(ft_strrchr(str, '\0'));
//	ft_putstr(strstr(str, dst));
//	ft_putstr(ft_strnstr(str, dst, 14));
//	ft_putnbr(strcmp(str, dst));
//	ft_putnbr(ft_strncmp(str, dst, 5));
//	ft_putnbr(ft_atoi(dst));
//	ft_putnbr(ft_isalpha(101));
//	ft_putnbr(ft_isdigit(50));
//	ft_putnbr(ft_isalnum(50));
//	ft_putnbr(ft_isascii(50));
//	ft_putnbr(ft_isprint(31));
//	ft_putnbr(ft_toupper(101));
//	ft_putnbr(ft_tolower(90));
//	res = ft_memalloc(3);
//	ft_memdel(&res);
//	ft_putstr(ft_strsub(str, 11, 10));
	if (ft_strjoin(dst, str))
		ft_putstr(ft_strjoin(dst, str));
//	res = ft_strtrim(str);
//	if ((fd = open("fichier", O_WRONLY |O_CREAT, S_IRWXU)) > -1)
//	{
//		ft_putstr("succes");
//		ft_putnbr_fd(-147483648, fd);
//	}
//	res = ft_strsplit(str, '*');
//	ft_putstr(ft_itoa(-2147483648));
//	res = ft_lstnew(str, ft_strlen(str));
//	ft_putstr(res->content);
	res = ft_strsplit_lst(str, '*');
//	res = ft_lstnew(str, ft_strlen(str));
	if (res == NULL)
		ft_putstr("NULL");
	while (res)
	{
		ft_putstr(res->content);
		ft_putchar('\n');
		res = res->next;
	}
	if (ac == 2)
	{
		str = ft_file_to_char(av[1]);
		ft_putstr(str);
	}
	ft_putstr("\nthe end\n");
	return (0);
}
