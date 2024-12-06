/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchagar <zchagar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:39:00 by zchagar           #+#    #+#             */
/*   Updated: 2024/06/11 10:30:57 by zchagar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (10);
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	*ft_free_split(char **p, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static char	*ft_dupword(const char *str, int start, int end)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(char) * (end - start + 1));
	if (!p)
		return (NULL);
	while (start < end)
	{
		p[i] = str[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

static void	ft_initvar(size_t *i, int *j, int *k)
{
	*i = -1;
	*j = -1;
	*k = -1;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	int		k;
	char	**p;

	ft_initvar(&i, &j, &k);
	if (!s)
		return (NULL);
	p = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!p)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			p[++j] = ft_dupword(s, k, i);
			if (!p[j])
				return (ft_free_split(p, ft_countwords(s, c)));
			k = -1;
		}
	}
	return (p);
}

/*int main()
{
	char **p;

	p = ft_split("hello!zzzzzzzz",'z');

	for (int i = 0; i <= 2; i++)
	{
		printf("%s\n", p[i]);
		free(p[i]);
	}
	free(p);
}
*/
