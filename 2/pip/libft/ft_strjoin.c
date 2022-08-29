/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinheo <jinheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:50:54 by jinheo            #+#    #+#             */
/*   Updated: 2022/07/10 20:41:45 by jinheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2);
static char	*ft_strcat(char *dst, const char *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	s1_size = 0;
	while (*(s1 + s1_size))
		s1_size++;
	s2_size = 0;
	while (*(s2 + s2_size))
		s2_size++;
	newstr = (char *) malloc (s1_size + s2_size + 1);
	if (!newstr)
		return (NULL);
	*newstr = 0;
	newstr = ft_strcat(newstr, s1);
	newstr = ft_strcat(newstr, s2);
	return (newstr);
}

static char	*ft_strcat(char *dst, const char *src)
{
	size_t	start_location;
	size_t	copied_size;

	start_location = 0;
	while (*(dst + start_location))
		start_location++;
	copied_size = 0;
	while (*(src + copied_size))
	{
		*(dst + start_location + copied_size) = *(src + copied_size);
		copied_size++;
	}	
	*(dst + start_location + copied_size) = 0;
	return (dst);
}
