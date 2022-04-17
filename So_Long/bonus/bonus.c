/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:09:17 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/14 16:37:56 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

int	main(int ac, char **av)
{
	t_type	*mcq;

	mcq = malloc(sizeof(t_type));
	if (!mcq)
		return (0);
	if (ac != 2)
		ft_exit("\nHatali Arguman Gonderimi", &mcq);
	if (!isber(av[1]) || !ft_init_map(&mcq, av))
		ft_exit("\nHarita Yukelemde Sorun Bulunmakta", &mcq);
	mlx_key_hook(mcq->window, key_pressed, &mcq);
	mcq->pla_dia_speed = 0;
	mcq->player_index = 0;
	mcq->diamond_index = 0;
	mcq->enemy_speed = 0;
	mlx_loop_hook(mcq->mlx, ft_animator, &mcq);
	mlx_hook(mcq->window, 17, 0, exit_hook, &mcq);
	mlx_loop(mcq->mlx);
	return (0);
}
