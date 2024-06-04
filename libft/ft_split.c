/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojo <sojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:32:52 by sojo              #+#    #+#             */
/*   Updated: 2024/04/29 14:28:52 by sojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *str, char delim)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == delim)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != delim)
			i++;
	}
	return (count);
}

static char	*ft_extract_word(const char *str, char delim)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	while (str[len] && str[len] != delim)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*ft_word_into_array(
	const char *str, char delim,
	size_t i, char **arr)
{
	if (!str)
		return (NULL);
	arr[i] = ft_extract_word(str, delim);
	if (!arr[i])
	{
		while (i > 0)
		{
			i--;
			free(arr[i]);
		}
		free(arr);
		return (NULL);
	}
	return (arr[i]);
}

char	**ft_split(const char *s, char c)
{
	size_t	nb_words;
	size_t	i;
	char	**word_arr;

	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	word_arr = malloc(sizeof(char *) * (nb_words + 1));
	if (!word_arr)
		return (NULL);
	i = -1;
	while (++i < nb_words)
	{
		while (*s && *s == c)
			s++;
		word_arr[i] = ft_word_into_array(s, c, i, word_arr);
		if (word_arr[i] == NULL)
			return (NULL);
		while (*s && *s != c)
			s++;
	}
	word_arr[i] = NULL;
	return (word_arr);
}
