/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 13:07:17 by jsivanes          #+#    #+#             */
/*   Updated: 2015/11/05 19:59:59 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_arg(char *argv)
{
	int		i;

	i = 0;
	while (argv[i] != '\0')
		i++;
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	char	*str;
	int		j;
	int		j_str;

	i = 0;
	j = 0;
	j_str = 0;
	while (++i < argc)
		j += ft_count_arg(argv[i]);
	if (!(str = (char *)malloc(sizeof(str) * (j + 1))))
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			str[j_str++] = argv[i][j++];
		if (i < argc - 1)
		{
			str[j_str++] = '\n';
		}
	}
	str[j_str] = '\0';
	return (str);
}
