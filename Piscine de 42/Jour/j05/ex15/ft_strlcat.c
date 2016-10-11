/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 17:51:31 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/31 16:25:55 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	u;
	unsigned int	y;
	unsigned int	z;

	i = 0;
	u = 0;
	y = 0;
	z = 0;
	while (dest[u] != '\0')
		u++;
	while (src[i] != '\0')
		i++;
	if (u > size)
		return (u + i - (u - size));
	y = u;
	while (src[z] != '\0' && y + 1 < size)
	{
		dest[y] = src[z];
		y++;
		z++;
	}
	dest[y] = '\0';
	return (u + i);
}
