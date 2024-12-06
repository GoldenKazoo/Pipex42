/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:14:29 by zchagar           #+#    #+#             */
/*   Updated: 2024/05/28 13:43:04 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int character)
{
	if (ft_isalpha(character) == 1)
	{
		if (character <= 'Z' && character >= 'A')
		{
			return (character + 32);
		}
	}
	return (character);
}

/*int	main()
{
	printf("%c", ft_tolower('C'));
	printf("%c", ft_tolower('\n'));
	printf("%c", ft_tolower('c'));
	printf("%c", ft_tolower('\n'));
}*/
