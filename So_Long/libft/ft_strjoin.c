/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:27:43 by rtosun            #+#    #+#             */
/*   Updated: 2022/02/04 16:46:19 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dizi;
	size_t	len;
	size_t	i;
	int		a;

	i = 0;
	a = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	dizi = malloc(sizeof(char) * len + 1);
	if (!dizi)
		return (NULL);
	while (i < len)
	{
		if (i < ft_strlen(s1))
			dizi[i] = s1[i];
		else
			dizi[i] = s2[a++];
		i++;
	}
	dizi[i] = '\0';
	return (dizi);
}
