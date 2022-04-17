/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecayir <ecayir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:13:40 by ecayir            #+#    #+#             */
/*   Updated: 2022/04/14 16:21:38 by ecayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "stdbool.h"
# include "fcntl.h"
# include "unistd.h"
# include "../minilibx/mlx.h"

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

typedef struct game
{
	char	**map;
	int		random;
	int		line_size;
	int		colon_size;
	int		player_x;
	int		player_y;
	int		diamond_count;
	int		picture_size;
	int		move;
	void	*window;
	void	*mlx;
	void	*bg;
	void	*exit;
	void	*player;
	void	*diamond;
	void	*obstacle;
}	t_type;

void	ft_exit(char *s, t_type **mcq);
bool	isber(char *s);
bool	check_walls(t_type *mcq, int x, int y);
bool	check_objects(t_type *mcq, int x, int y);
char	**ft_split_fs(char *str, char *charset, int *ln);
char	*ft_read_map(int fd);
int		exit_hook(t_type **mcq);
void	ft_mlx_put_window(t_type **mcq, void *obje, int x, int y);
int		key_pressed(int key_code, t_type **mcq);
void	convert_to_xpm(t_type **mcq);
bool	ft_init_map(t_type **mcq, char **av);
bool	ft_create_map(t_type **mcq);
void	*ft_mlx_file_image(t_type **mcq, char *path);
#endif
