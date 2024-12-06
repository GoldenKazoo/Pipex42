/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:15:14 by zchagar           #+#    #+#             */
/*   Updated: 2024/06/11 09:26:02 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	k;
	int	nb;

	i = 0;
	nb = 0;
	k = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
	{
		i++;
	}
	k = i;
	if (s[i] == '+' || s[i] == '-')
		i = i + 1;
	while (s[i] != '\0' && ft_isdigit(s[i]))
	{
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	if (s[k] == '-')
		return (-1 * nb);
	return (nb);
}

/*int	main()
{
	printf("%d",ft_atoi("-5"));
	printf("%c", '\n');
	printf("%d",atoi("-5"));
}*/
