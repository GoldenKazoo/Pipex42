/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:08:13 by zchagar           #+#    #+#             */
/*   Updated: 2024/05/28 09:55:52 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if (ft_isalpha(character) == 1)
	{
		return (1);
	}
	if (ft_isdigit(character) == 1)
	{
		return (1);
	}
	return (0);
}
