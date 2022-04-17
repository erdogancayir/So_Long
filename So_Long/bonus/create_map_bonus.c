/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:44:15 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/15 13:04:10 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	ft_mlx_put_window(t_type **mcq, void *obje, int x, int y)
{
	mlx_put_image_to_window((*mcq)->mlx, (*mcq)->window, obje,
		x * (*mcq)->picture_size, y * (*mcq)->picture_size);
}

void	ft_create_objects(t_type **mcq, char obje, int x, int y)
{
	if (obje == '0')
		ft_mlx_put_window(mcq, (*mcq)->bg, x, y);
	else if (obje == '1')
		ft_mlx_put_window(mcq, (*mcq)->obstacle, x, y);
	else if (obje == 'C')
	{
		(*mcq)->diamond_count++;
		ft_mlx_put_window(mcq, (*mcq)->diamond[0], x, y);
	}
	else if (obje == 'P')
	{
		ft_mlx_put_window(mcq, (*mcq)->player[0], x, y);
		(*mcq)->player_x = x;
		(*mcq)->player_y = y;
	}
	else if (obje == 'E')
		ft_mlx_put_window(mcq, (*mcq)->exit, x, y);
	else if (obje == 'N')
		ft_mlx_put_window(mcq, (*mcq)->enemy, x, y);
}

bool	ft_create_map(t_type **mcq)
{
	int	x;
	int	y;

	y = -1;
	(*mcq)->picture_size = 50;
	(*mcq)->mlx = mlx_init();
	(*mcq)->window = mlx_new_window((*mcq)->mlx,
			(*mcq)->line_size * (*mcq)->picture_size,
			(*mcq)->colon_size * (*mcq)->picture_size,
			"FireBoyAndWaterGirlGame");
	convert_to_xpm(mcq);
	(*mcq)->diamond_count = 0;
	(*mcq)->move = 0;
	while (++y < (*mcq)->colon_size)
	{
		x = -1;
		while (++x < (*mcq)->line_size)
		{
			ft_create_objects(mcq, (*mcq)->map[y][x], x, y);
		}
	}
	return (true);
}
