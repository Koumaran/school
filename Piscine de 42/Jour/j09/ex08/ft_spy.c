/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 16:29:55 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/23 16:35:06 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*jp_ltrim(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

char	*jp_rtrim(char *str)
{
	char	*e;
	int		i;

	i = 0;
	while (str[i])
		i++;
	e = str + i;
	while (*--e == ' ')
		*(e + 1) = '\0';
	return (str);
}

char	*jp_trim(char *str)
{
	return (jp_rtrim(jp_ltrim(str)));
}

int		jp_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			s1[i] = s1[i] - 'A' + 'a';
		i++;
	}
	while (*s1++ == *s2++)
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
	return (*--s1 - *--s2);
}

int		main(int argc, char **argv)
{
	int		i;
	int		a;

	a = 0;
	i = 1;
	if (argc > 1)
		while (i < argc)
		{
			if (jp_strcmp(jp_trim(argv[i]), "president") == 0)
				a = 1;
			else if (jp_strcmp(jp_trim(argv[i]), "attack") == 0)
				a = 1;
			else if (jp_strcmp(jp_trim(argv[i]), "powers") == 0)
				a = 1;
			i++;
		}
	if (a == 1)
		write(1, "Alert!!!\n", 9);
	return (0);
}
