/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 18:44:44 by jsivanes          #+#    #+#             */
/*   Updated: 2016/10/13 19:04:08 by jsivanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**ft_memcpy_tab(void **src, void **dest, size_t n)
{
	unsigned char	**tmp_dest;
	unsigned char	**tmp_src;

	tmp_dest = (unsigned char **)dest;
	tmp_src = (unsigned char **)src;
	while (n--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}
