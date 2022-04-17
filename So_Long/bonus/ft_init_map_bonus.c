/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:34:05 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/14 16:21:39 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"
#include "../include/colors.h"

bool	ft_init_map(t_type **mcq, char **av)
{
	int		fd;
	char	*map;

	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		ft_exit("DF Hatasi, Dosya Acilamadi", mcq);
	map = ft_read_map(fd);
	(*mcq)->map = ft_split_fs(map, "\n", &(*mcq)->colon_size);
	free(map);
	close(fd);
	(*mcq)->line_size = ft_strlen((*mcq)->map[0]);
	if (!check_walls(*mcq, -1, -1) || !check_objects(*mcq, -1, -1))
		return (false);
	if (!ft_create_map(mcq))
		return (false);
	return (true);
}
