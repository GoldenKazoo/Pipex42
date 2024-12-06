/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:15:27 by zchagar           #+#    #+#             */
/*   Updated: 2024/05/29 14:27:47 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	i = 0;
	ns1 = (unsigned char *) s1;
	ns2 = (unsigned char *) s2;
	while (i < n)
	{
		if (ns1[i] != ns2[i])
		{
			return (ns1[i] - ns2[i]);
		}
		i++;
	}
	return (0);
}
