/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:14:13 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/14 16:29:35 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/colors.h"

bool	isber(char *s)
{
	char	*find;

	find = ft_strrchr(s, '.');
	if (!find || ft_strlen(find) != 4)
		return (false);
	if (ft_strncmp(find, ".ber", 4) == 0)
		return (true);
	return (false);
}

bool	check_objects(t_type *mcq, int x, int y)
{
	int	*arr;
	int	i;

	i = 0;
	arr = ft_calloc(3, sizeof(int));
	while (++y < mcq->colon_size)
	{
		x = -1;
		while (++x < mcq->line_size)
		{
			if (mcq->map[y][x] == 'E')
				arr[0]++;
			else if (mcq->map[y][x] == 'C')
				arr[1]++;
			else if (mcq->map[y][x] == 'P')
				arr[2]++;
		}
	}
	if (arr[0] == 0 || arr[1] == 0 || arr[2] != 1)
	{
		free(arr);
		ft_exit("Izin Verilmeyen Sayida Haritada Obje Sayisi", &mcq);
	}
	free(arr);
	return (true);
}

bool	check_walls(t_type *mcq, int x, int y)
{
	while (++y < mcq->colon_size)
	{
		if (ft_strlen(mcq->map[y]) != mcq->line_size)
			ft_exit("Harita Dikdortgen Olmalidir", &mcq);
		x = -1;
		while (++x < mcq->line_size)
		{
			if (mcq->map[y][x] != '1' && (y == 0 || y == mcq->colon_size - 1))
				ft_exit("Alt ve Ust Kenarlar Kapali Olmalidir.", &mcq);
			else if (mcq->map[y][x] != '1' && (x == 0 ||
						x == mcq->line_size -1))
				ft_exit("Sag ve Sol Kenar Kapali Olmalidir.", &mcq);
			else if (!ft_strchr("CEP01", mcq->map[y][x]))
				ft_exit("Haritada Tanimlanmayan Obje Girisi", &mcq);
		}
	}
	return (true);
}
