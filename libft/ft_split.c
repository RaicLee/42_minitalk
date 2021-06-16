/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:33:21 by jealee            #+#    #+#             */
/*   Updated: 2020/12/29 01:38:18 by jealee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_word_count(char const *s, char c)
{
	size_t	index;
	size_t	ret;

	index = 0;
	ret = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			ret++;
			while (s[index] && s[index] != c)
				index++;
		}
		else
			index++;
	}
	return (ret);
}

static void		ft_freeallmemory(char **ret, size_t index)
{
	size_t start;

	start = 0;
	while (start < index)
	{
		free(ret[start]);
		start++;
	}
	free(ret);
}

static void		ft_cpystr(char *dest, const char *src, size_t start, size_t end)
{
	size_t index;

	index = 0;
	while (start < end)
	{
		dest[index] = src[start];
		index++;
		start++;
	}
	dest[index] = '\0';
}

static void		ft_make_split(char const *s, char c, char **ret)
{
	size_t	index;
	size_t	temp;
	size_t	retbase;

	index = 0;
	retbase = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			temp = index;
			while (s[index] && s[index] != c)
				index++;
			ret[retbase] = (char *)malloc(sizeof(char) * (index - temp + 1));
			if (!ret[retbase])
			{
				ft_freeallmemory(ret, retbase);
				return ;
			}
			ft_cpystr(ret[retbase], s, temp, index);
			retbase++;
		}
		else
			index++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	wordcount;

	if (!s)
		return (0);
	wordcount = ft_get_word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!result)
		return (0);
	result[wordcount] = NULL;
	if (!wordcount)
		return (result);
	ft_make_split(s, c, result);
	return (result);
}
