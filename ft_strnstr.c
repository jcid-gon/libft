/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:52:28 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/06/01 12:08:47 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	s;
	size_t	f;

	s = 0;
	f = 0;
	if (to_find[0] == '\0')
		return ((char *) str);
	if (len == 0)
		return (NULL);
	while (str[s] != '\0' && s < len - 1)
	{
		while (str[s] == to_find[f] && to_find[f] != '\0' && s < len)
		{
			f++;
			s++;
		}
		if (to_find[f] == '\0')
			return (&((char *)str)[s - f]);
		else
			f = 0;
		s++;
	}
	return (NULL);
}
