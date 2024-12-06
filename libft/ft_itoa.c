/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:05:57 by zchagar           #+#    #+#             */
/*   Updated: 2024/06/11 10:57:51 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_getrange(int n)
{
	long int		i;
	long int		nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		i = 1;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	int			range;
	long int	nb;
	char		*p;

	i = 1;
	nb = n;
	range = ft_getrange(nb);
	p = malloc(sizeof(char) * (range + 1));
	if (!p)
		return (NULL);
	if (nb < 0)
		nb = nb * -1;
	while (i <= range)
	{
		p[range - i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	p[range] = '\0';
	if (n < 0)
		p[0] = '-';
	return (p);
}
/*int main()
{
	printf("%s", ft_itoa(0));
}
*/
