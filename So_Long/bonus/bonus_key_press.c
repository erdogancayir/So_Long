/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_key_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:02:48 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/15 13:03:59 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	balon(t_type **mcq, int x, int y)
{
	while (++y < (*mcq)->colon_size)
	{
		x = -1;
		while (++x < (*mcq)->line_size)
		{
			if ((*mcq)->map[y][x] == 'N')
			{
				(*mcq)->enemy = ft_mlx_file_image((*mcq)->mlx,
						"./sprites/balon.xpm");
				mlx_put_image_to_window((*mcq)->mlx,
					(*mcq)->window, (*mcq)->enemy,
					x * (*mcq)->picture_size, y * (*mcq)->picture_size);
			}
		}
	}
}

void	ft_move(t_type **mcq, int x, int y)
{
	char	*str;

	ft_mlx_put_window(mcq, (*mcq)->bg, (*mcq)->player_x,
		(*mcq)->player_y);
	ft_mlx_put_window(mcq, (*mcq)->player[0], (*mcq)->player_x + x,
		(*mcq)->player_y + y);
	(*mcq)->map[(*mcq)->player_y][(*mcq)
		->player_x] = '0';
	(*mcq)->map[(*mcq)->player_y + y][(*mcq)
		->player_x + x] = 'P';
	(*mcq)->player_x += x;
	(*mcq)->player_y += y;
	(*mcq)->move++;
	ft_printf("\33[2K\r\033[0;96mHarket Sayisi : %i", (*mcq)->move);
	str = ft_itoa((*mcq)->move);
	mlx_put_image_to_window((*mcq)->mlx, (*mcq)->window,
		(*mcq)->obstacle, 200, 0);
	mlx_put_image_to_window((*mcq)->mlx, (*mcq)->window,
		(*mcq)->obstacle, 250, 0);
	mlx_string_put((*mcq)->mlx, (*mcq)->window,
		200, 20, 0x00FFFFFF, "MOVES :");
	mlx_string_put((*mcq)->mlx, (*mcq)->window,
		250, 20, 0x00FFFFFF, str);
	free(str);
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
				(*mcq)->exit = ft_mlx_file_image(mcq,
						"./sprites/exit2.xpm");
				mlx_put_image_to_window((*mcq)->mlx,
					(*mcq)->window, (*mcq)->exit,
					x * (*mcq)->picture_size, y * (*mcq)->picture_size);
			}
		}
	}
}

void	ft_ismove(t_type **mcq, int x, int y)
{
	if ((*mcq)->map[(*mcq)->player_y + y][(*mcq)->player_x + x] == '0')
		ft_move(mcq, x, y);
	else if ((*mcq)->map[(*mcq)->player_y + y][(*mcq)->player_x + x] == 'C')
	{
		ft_move(mcq, x, y);
		(*mcq)->diamond_count--;
	}
	else if ((*mcq)->map[(*mcq)->player_y + y][(*mcq)->player_x + x] == 'E')
	{
		if ((*mcq)->diamond_count == 0)
		{
			ft_printf("\033[0;92m\nTEBRIKLER\033[0;94m****\n");
			exit_hook(mcq);
		}
		else
			ft_printf("\33[2K\r\033[0;94m%d Adet Elmas Bulunmakta!",
				(*mcq)->diamond_count);
	}
	else if ((*mcq)->map[(*mcq)->player_y + y][(*mcq)->player_x + x] == 'N')
	{
		ft_printf(" \033[0;92m*_* KAYBETTIN! *_*");
		exit_hook(mcq);
	}
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
	else if (key_code == KEY_C)
		balon(mcq, -1, -1);
	return (0);
}
