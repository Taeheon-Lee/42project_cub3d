/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:03:28 by tlee              #+#    #+#             */
/*   Updated: 2020/05/22 14:12:36 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define TILE_SIZE 32
# define MAP_NUM_ROWS 11
# define MAP_NUM_COLS 15
# define WINDOW_WIDTH MAP_NUM_COLS * TILE_SIZE
# define WINDOW_HEIGHT MAP_NUM_ROWS * TILE_SIZE
# define _USE_MATH_DEFINES
# include "/home/taeheon/minilibx_linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_player {
	double	x;
	double	y;
	double	radius;
	double	turndirection;
	double	walkdirection;
	double	rotationangle;
	double	movespeed;
	double	rotationspeed;
}				t_player;

void			draw_grid(void *mlx_ptr, void *win_ptr, int row, int col, int num);
void            draw_window(void *mlx_ptr, void *win_ptr);
void            draw_player(void *mlx_ptr, void *win_ptr);
t_player        *set_player(void);

#endif
