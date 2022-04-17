/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:45:48 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/14 16:21:42 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	*ft_mlx_file_image(t_type **mcq, char *path)
{
	return (mlx_xpm_file_to_image((*mcq)->mlx, path,
			&(*mcq)->random, &(*mcq)->random));
}

void	ft_player(t_type **mcq)
{
	(*mcq)->player[0] = ft_mlx_file_image(mcq, "./sprites/car.xpm");
	(*mcq)->player[1] = ft_mlx_file_image(mcq, "./sprites/car_2.xpm");
}

void	ft_diamond(t_type **mcq)
{
	(*mcq)->diamond[0] = ft_mlx_file_image(mcq, "./sprites/racing_line.xpm");
	(*mcq)->diamond[1] = ft_mlx_file_image(mcq, "./sprites/diamond.xpm");
}

void	convert_to_xpm(t_type **mcq)
{
	ft_player(mcq);
	ft_diamond(mcq);
	(*mcq)->bg = ft_mlx_file_image(mcq, "./sprites/ways.xpm");
	(*mcq)->enemy = ft_mlx_file_image(mcq, "./sprites/police.xpm");
	(*mcq)->obstacle = ft_mlx_file_image(mcq, "./sprites/trap.xpm");
	(*mcq)->exit = ft_mlx_file_image(mcq, "./sprites/exit.xpm");
}
