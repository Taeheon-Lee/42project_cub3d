/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:03:17 by tlee              #+#    #+#             */
/*   Updated: 2020/05/22 17:29:15 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void		draw_grid(void *mlx_ptr, void *win_ptr, int row, int col, int num)
{
	int row_cnt;
	int col_cnt;
	int col_tmp;

	row_cnt = -1;
	while (++row_cnt < 32)
	{
		col_tmp = col;
		col_cnt = -1;
		while (++col_cnt < 32)
		{
			if (num == 0)
				mlx_pixel_put(mlx_ptr, win_ptr, col_tmp, row, 0x000000);
			else if (num == 1)
				mlx_pixel_put(mlx_ptr, win_ptr, col_tmp, row, 0xC0C0C0);
			col_tmp++;
		}
		row++;
	}
}

void		draw_window(void *mlx_ptr, void *win_ptr)
{
	int i;
	int j;

	i = -1;
	while (++i < MAP_NUM_ROWS)
	{
		j = -1;
		while (++j < MAP_NUM_COLS)
		{
			if (map[i][j] == 1)
				draw_grid(mlx_ptr, win_ptr, i * 32, j * 32, 1);
			else
				draw_grid(mlx_ptr, win_ptr, i * 32, j * 32, 0);
		}
	}
}

t_player	*set_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->radius = 3;
	player->turndirection = 0;
	player->walkdirection = 0;
	player->rotationangle = M_PI / 2;
	player->movespeed = 2;
	player->rotationspeed = 2 * (M_PI / 180);
	return (player);
}

void		draw_player(void *mlx_ptr, void *win_ptr)
{
	double		i;
	double		j;
	double		r;
	t_player	*player;

	r = 2;
	i = (WINDOW_WIDTH / 2) - r - 1;
	player = set_player();
	while (++i <= (WINDOW_WIDTH / 2 + r))
	{
		j = (WINDOW_HEIGHT / 2) - r - 1;
		while (++j <= (WINDOW_HEIGHT / 2 + r))
			if (pow((WINDOW_WIDTH / 2 - i), 2) + pow((WINDOW_HEIGHT / 2 - j), 2) <= pow(r, 2))
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFd700);
	}
	i = WINDOW_WIDTH / 2;
	j = WINDOW_HEIGHT / 2 - 1;
	while (++j <= WINDOW_HEIGHT / 2 + 10)
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFd700);
}

int			main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	draw_window(mlx_ptr, win_ptr);
	draw_player(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
