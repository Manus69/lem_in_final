/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:49:31 by lcaesar           #+#    #+#             */
/*   Updated: 2019/12/17 14:46:17 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *string, char separator)
{
	int		word_count;
	int		outside;

	outside = 1;
	word_count = 0;
	while (*string != '\0')
	{
		if (*string != separator && outside)
		{
			word_count = word_count + 1;
			outside = 0;
			string = string + 1;
		}
		else if (*string == separator && !outside)
		{
			outside = 1;
			string = string + 1;
		}
		else
			string = string + 1;
	}
	return (word_count);
}

static int	count_letters_until(char const *start, char c)
{
	int		number_of_letters;

	number_of_letters = 0;
	while (*start != c && *start != '\0')
	{
		number_of_letters = number_of_letters + 1;
		start = start + 1;
	}
	return (number_of_letters);
}

static char	**very_useful(char **array, int index)
{
	while (index >= 0)
	{
		free(array[index]);
		index = index - 1;
	}
	return (NULL);
}

static char	*get_word(char const *s, char c)
{
	char	*word;
	int		word_length;

	word_length = count_letters_until(s, c);
	word = (char *)malloc(sizeof(char) * (word_length + 1));
	if (!word)
		return (NULL);
	while (*s != c && *s != '\0')
	{
		*word = *s;
		word = word + 1;
		s = s + 1;
	}
	*word = '\0';
	return (word - word_length);
}

char		**ft_strsplit(char const *s, char c)
{
	int		j;
	int		word_count;
	char	**words;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	j = 0;
	while (j < word_count)
	{
		while (*s == c)
			s = s + 1;
		words[j] = get_word(s, c);
		if (words[j] == NULL)
			return (very_useful(words, j - 1));
		s = s + ft_strlen(words[j]);
		j = j + 1;
	}
	words[j] = NULL;
	return (words);
}
