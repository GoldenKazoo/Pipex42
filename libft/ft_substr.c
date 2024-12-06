/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:13:09 by zchagar           #+#    #+#             */
/*   Updated: 2024/06/10 10:53:53 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			p[j++] = s[i];
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}

/*int main()
{
	printf("%s", ft_substr("", 0, 1));
}
*/
