/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:40:06 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/14 16:40:55 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	ft_move_anim(t_type **mcq, int x, int y, char obje)
{
	if (obje == 'P')
	{
		if ((*mcq)->player_index >= 2)
			(*mcq)->player_index = 0;
		ft_mlx_put_window(mcq, (*mcq)->player[(*mcq)->player_index], x, y);
		(*mcq)->player_index++;
	}
	else if (obje == 'C')
	{
		if ((*mcq)->diamond_index >= 2)
			(*mcq)->diamond_index = 0;
		ft_mlx_put_window(mcq, (*mcq)->diamond[(*mcq)->diamond_index], x, y);
	}
}

void	ft_is_move_anim(t_type **mcq, int x, int y)
{
	while (++y < (*mcq)->colon_size)
	{
		x = -1;
		while (++x < (*mcq)->line_size)
		{
			if ((*mcq)->map[y][x] == 'C')
				ft_move_anim(mcq, x, y, 'C');
			else if ((*mcq)->map[y][x] == 'P')
				ft_move_anim(mcq, x, y, 'P');
		}
	}
	(*mcq)->diamond_index++;
}

void	ft_move_enemy(t_type **mcq, int x, int y)
{
	if ((*mcq)->map[y][x + 1] == 'P' || (*mcq)->map[y][x - 1] == 'P')
		exit_hook(mcq);
	else if ((*mcq)->map[y][x + 1] == '0')
	{
		ft_mlx_put_window(mcq, (*mcq)->enemy, x + 1, y);
		ft_mlx_put_window(mcq, (*mcq)->bg, x, y);
		(*mcq)->map[y][x] = '0';
		(*mcq)->map[y][x + 1] = 'N';
	}
	else
	{
		ft_mlx_put_window(mcq, (*mcq)->bg, x, y);
		(*mcq)->map[y][x] = '0';
		while ((*mcq)->map[y][x] != '1' && (*mcq)->map[y][x] != 'E')
			x--;
		if ((*mcq)->map[y][x + 1] == 'P')
			exit_hook(mcq);
		ft_mlx_put_window(mcq, (*mcq)->enemy, x + 1, y);
		(*mcq)->map[y][x + 1] = 'N';
	}
}

void	ft_ismove_enemy(t_type **mcq, int x, int y)
{
	while (++y < (*mcq)->colon_size)
	{
		x = -1;
		while (++x < (*mcq)->line_size)
		{
			if ((*mcq)->map[y][x] == 'N')
			{
				ft_move_enemy(mcq, x, y);
				x += 1;
			}
		}
	}
}

int	ft_animator(t_type **mcq)
{
	(*mcq)->pla_dia_speed++;
	(*mcq)->enemy_speed++;
	if ((*mcq)->pla_dia_speed >= 3000)
	{
		ft_is_move_anim(mcq, -1, -1);
		(*mcq)->pla_dia_speed = 0;
	}
	if ((*mcq)->enemy_speed >= 5000)
	{
		ft_ismove_enemy(mcq, -1, -1);
		(*mcq)->enemy_speed = 0;
	}
	return (0);
}
