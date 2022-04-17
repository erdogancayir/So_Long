/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:56:44 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/08 13:51:02 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	new_str = (char *)malloc(len + 1);
	if (!s || !new_str)
		return (0);
	while (i < ft_strlen(s) && j < len)
	{
		new_str[j++] = s[i++];
	}
	new_str[j] = '\0';
	return (new_str);
}
