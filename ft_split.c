/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:41:31 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/06/04 11:41:34 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free (char **array)
{
	unsigned int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
	return (NULL);
}

void	ft_fill(const char *s, char c, char **array, size_t count)
{
	int	y;
	int	x;
	int	index;

	y = 0;
	x = 0;
	index = 0;
	while (s[index] == c)
		index++;
	while (s[index] != '\0')
	{
		if (s[index] != c)
			array[y][x++] = s[index];
		if (s[index] == c)
		{
			while (s[index + 1] == c)
				index++;
			array[y][x] = '\0';
			y++;
			x = 0;
		}
		index++;
	}
	if (y != 0)
		array[count] = NULL;
}

void	ft_assing_malloc(char const *s, char c, char **array)
{
	int	count;
	int	y;
	int	index;

	y = 0;
	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
			count++;
		else if (index > 0 && s[index - 1] != c)
		{
			array[y] = malloc((count + 1) * sizeof(char));
			count = 0;
			y++;
		}
		index++;
	}
	if (count != 0)
		array[y] = malloc((count + 1) * sizeof(char));
}

size_t	ft_nb_row (char const *s, char c)
{
	size_t	count;
	int		index;

	index = 0;
	count = 0;
	while (s[index] == c)
		index++;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			while (s[index] == c)
				index++;
			count++;
		}
		index++;
	}
	if (s[0] != c)
		count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_nb_row(s, c);
	array = malloc (sizeof(char *) * (count + 1));
	if (array == NULL)
		return (NULL);
	ft_assing_malloc(s, c, array);
	if (!array)
		return (ft_free(array));
	ft_fill(s, c, array, count);
	return (array);
}
