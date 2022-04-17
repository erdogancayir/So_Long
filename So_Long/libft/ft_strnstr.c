/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:06:52 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/03 15:37:46 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *h, const char *find, size_t len)
{
	size_t	c;

	if (*find == '\0' || h == find)
		return ((char *)h);
	c = ft_strlen(find);
	while (*h && c <= len--)
	{
		if (!(ft_strncmp((char *)h, (char *)find, c)))
			return ((char *)h);
		h++;
	}
	return (NULL);
}
