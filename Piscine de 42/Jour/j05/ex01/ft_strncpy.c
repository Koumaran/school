/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 20:14:37 by jsivanes          #+#    #+#             */
/*   Updated: 2015/10/28 18:28:07 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	while (n--)
		dest[i++] = '\0';
	return (dest);
}
