/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver_to_xpm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:40:10 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/14 16:21:29 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_mlx_file_image(t_type **mcq, char *path)
{
	return (mlx_xpm_file_to_image((*mcq)->mlx, path, &(*mcq)->random,
			&(*mcq)->random));
}

void	convert_to_xpm(t_type **mcq)
{
	(*mcq)->player = ft_mlx_file_image(mcq, "./sprites/car.xpm");
	(*mcq)->bg = ft_mlx_file_image(mcq, "./sprites/ways.xpm");
	(*mcq)->diamond = ft_mlx_file_image(mcq, "./sprites/racing_line.xpm");
	(*mcq)->obstacle = ft_mlx_file_image(mcq, "./sprites/trap.xpm");
	(*mcq)->exit = ft_mlx_file_image(mcq, "./sprites/exit.xpm");
}
