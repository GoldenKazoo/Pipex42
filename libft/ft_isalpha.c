/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:02:09 by zchagar           #+#    #+#             */
/*   Updated: 2024/05/28 09:55:40 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if (character <= 'Z' && 'A' <= character)
	{
		return (1);
	}
	if (character <= 'z' && 'a' <= character)
	{
		return (1);
	}
	return (0);
}

/*int	main()
{
	int i;

	i = 0;
	while(i <= 127)
	{
		if ( i % 10 == 0 )
		{
		 (printf("%c", '\n'));
		}

		if ( i % 3 == 0 )
		{
		 (printf("%c", '\n'));
		}
		printf("%d :", i);
		printf("%d", ft_isalpha(i));
		printf("%s", "  ");
		i++;
	}
}*/
