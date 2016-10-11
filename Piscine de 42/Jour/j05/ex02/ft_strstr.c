/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 20:35:54 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/29 12:23:59 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		d;
	int		j;

	i = 0;
	if (to_find[0] == '\0' && to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = i;
		d = 0;
		while (str[j] == to_find[d])
		{
			j++;
			d++;
			if (to_find[d] == '\0')
				return (str + i);
		}
		i++;
	}
	return (0);
}
