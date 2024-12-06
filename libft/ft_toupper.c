/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:11:18 by zchagar           #+#    #+#             */
/*   Updated: 2024/05/28 13:51:21 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int character)
{
	if (ft_isalpha(character) == 1)
	{
		if (character <= 'z' && character >= 'a')
		{
			return (character - 32);
		}
	}
	return (character);
}
