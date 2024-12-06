/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:01:23 by zchagar           #+#    #+#             */
/*   Updated: 2024/06/11 10:23:31 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementcount, size_t elementsize)
{
	void	*p;

	if (elementsize > 0 && elementcount > (UINT_MAX / elementsize))
		return (NULL);
	p = malloc(elementcount * elementsize);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, elementcount * elementsize);
	return (p);
}
/*int	main()
{
	void *p;

	p = calloc(10, 8);
	printf("%p", p);
	free(p);
}*/
