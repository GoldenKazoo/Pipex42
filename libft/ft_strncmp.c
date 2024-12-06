/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:38:43 by zchagar           #+#    #+#             */
/*   Updated: 2024/06/10 15:03:30 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (i < n - 1) && s1[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

/*int	main()
{
	printf("%d \n", ft_strncmp("abcdef", "abc\375xx", 5));
	printf("%d", strncmp("abcdef", "abc\375xx", 5));
}*/
