/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:27:33 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/15 13:02:49 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/colors.h"

void	free_map(t_type **mcq)
{
	int	i;

	i = 0;
	if (!(*mcq)->map)
	{
		while (i < (*mcq)->colon_size)
		{
			free((*mcq)->map[i]);
			i++;
		}
	}
}

void	ft_exit(char *s, t_type **mcq)
{
	ft_printf("\033[0;91m\nERROR\n\033[0;96m%s", s);
	free_map(mcq);
	exit(0);
}

static char	*ft_str_join(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i])
			str[i] = left_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_read_map(int fd)
{
	int		rd_bytes;
	char	map[2];
	char	*value;

	value = NULL;
	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, map, 1);
		map[rd_bytes] = '\0';
		value = ft_str_join(value, map);
	}
	return (value);
}

int	exit_hook(t_type **mcq)
{
	free((*mcq)->player);
	free((*mcq)->exit);
	free((*mcq)->bg);
	free((*mcq)->obstacle);
	free((*mcq)->diamond);
	free_map(mcq);
	mlx_destroy_window((*mcq)->mlx, (*mcq)->window);
	exit(0);
}
