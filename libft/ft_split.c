/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcerny <vcerny@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:30:18 by vcerny            #+#    #+#             */
/*   Updated: 2025/05/23 17:08:51 by vcerny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_partial_free(char **array, size_t j)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < j)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	ft_split_strlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_copy_words_to_array(char const *s, char c, char **word_array,
		t_split *structure)
{
	size_t	k;

	k = 0;
	word_array[structure->j] = (char *)malloc(sizeof(char)
			* (ft_split_strlen(&s[structure->i], c) + 1));
	if (!word_array[structure->j])
	{
		ft_partial_free(word_array, structure->j);
		return (0);
	}
	while (s[structure->i + k] != c && s[structure->i + k])
	{
		word_array[structure->j][k] = s[structure->i + k];
		k++;
	}
	word_array[structure->j][k] = '\0';
	structure->j++;
	return (1);
}

static size_t	ft_how_many_words(char const *s, char c)
{
	size_t	i;
	size_t	counter;
	char	previous;

	counter = 0;
	i = 0;
	previous = c;
	while (s[i])
	{
		if (previous == c && s[i] != c)
			counter++;
		previous = s[i];
		i++;
	}
	return (counter);
}

/**
 * @brief This function splits a string based on delimiter char that is
 * given. Returns an array of strings of all parts of the original string
 * delimited by the delimiter char.
 *
 * If an error occurs, the function guarantees freeing all memory that
 * was allocated so far and returning NULL.
 *
 * @param param1 (const char *) string to split
 * @param param2 (char) char delimiter
 * @return (char **) null terminated array of split substrings
 */
char	**ft_split(char const *s, char c)
{
	size_t	how_many_words;
	t_split	structure;
	char	**word_array;
	char	previous;

	if (!s)
		return (NULL);
	structure.i = 0;
	structure.j = 0;
	previous = c;
	how_many_words = ft_how_many_words(s, c);
	word_array = (char **)malloc(sizeof(char *) * (how_many_words + 1));
	if (!word_array)
		return (NULL);
	while (s[structure.i])
	{
		if (previous == c && s[structure.i] != c)
			if (!ft_copy_words_to_array(s, c, word_array, &structure))
				return (NULL);
		previous = s[structure.i++];
	}
	word_array[how_many_words] = NULL;
	return (word_array);
}
