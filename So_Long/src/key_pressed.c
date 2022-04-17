/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:54:01 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/15 13:01:41 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move(t_type **mcq, int x, int y)
{
	ft_mlx_put_window(mcq, (*mcq)->bg, (*mcq)->player_x,
		(*mcq)->player_y);
	ft_mlx_put_window(mcq, (*mcq)->player, (*mcq)->player_x + x,
		(*mcq)->player_y + y);
	(*mcq)->map[(*mcq)->player_y][(*mcq)
		->player_x] = '0';
	(*mcq)->map[(*mcq)->player_y + y][(*mcq)->player_x + x] = 'P';
	(*mcq)->player_x += x;
	(*mcq)->player_y += y;
	(*mcq)->move++;
	ft_printf("\33[2K\r\033[0;96mHarket Sayisi : %i", (*mcq)->move);
}

void	change(t_type **mcq, int x, int y)
{
	while (++y < (*mcq)->colon_size)
	{
		x = -1;
		while (++x < (*mcq)->line_size)
		{
			if ((*mcq)->map[y][x] == 'E')
			{
				(*mcq)->exit = ft_mlx_file_image(mcq, "./sprites/exit2.xpm");
				mlx_put_image_to_window((*mcq)->mlx, (*mcq)->window,
					(*mcq)->exit, x * (*mcq)->picture_size,
					y * (*mcq)->picture_size);
			}
		}
	}
}

void	ft_ismove(t_type **mcq, int x, int y)
{
	if ((*mcq)->map[(*mcq)->player_y
			+ y][(*mcq)->player_x + x] == '0')
		ft_move(mcq, x, y);
	else if ((*mcq)->map[(*mcq)->player_y
			+ y][(*mcq)->player_x + x] == 'C')
	{
		ft_move(mcq, x, y);
		(*mcq)->diamond_count--;
		if ((*mcq)->diamond_count == 0)
			change(mcq, -1, -1);
	}
	else if ((*mcq)->map[(*mcq)->player_y + y]
		[(*mcq)->player_x + x] == 'E')
	{
		if ((*mcq)->diamond_count == 0)
		{
			ft_printf("\033[0;94m\n****\033[0;92mTEBRIKLER\033[0;94m****\n");
			exit(0);
		}
		else
			ft_printf("\33[2K\r\033[0;94m%d Adet Elmas Bulunmakta!",
				(*mcq)->diamond_count);
	}
	else
		ft_printf("\33[2K\r\033[0;91m---ENGEL OLAN BOLGE---");
}

int	key_pressed(int key_code, t_type **mcq)
{
	if (key_code == KEY_ESC)
		exit_hook(mcq);
	else if (key_code == KEY_A)
		ft_ismove(mcq, -1, 0);
	else if (key_code == KEY_S)
		ft_ismove(mcq, 0, 1);
	else if (key_code == KEY_W)
		ft_ismove(mcq, 0, -1);
	else if (key_code == KEY_D)
		ft_ismove(mcq, 1, 0);
	return (0);
}
