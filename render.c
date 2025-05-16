/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:12:56 by lbard             #+#    #+#             */
/*   Updated: 2025/05/06 03:12:56 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->strawberry = mlx_xpm_file_to_image(game->mlx, "assets/strawberry.xpm",
			&w, &h);
	game->background = mlx_xpm_file_to_image(game->mlx, "assets/background.xpm",
			&w, &h);
	game->end = mlx_xpm_file_to_image(game->mlx, "assets/end.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w, &h);
	game->frog = mlx_xpm_file_to_image(game->mlx, "assets/frog.xpm", &w, &h);
	game->frog_jump = mlx_xpm_file_to_image(game->mlx, "assets/frog_jump.xpm",
			&w, &h);
	game->frog_left = mlx_xpm_file_to_image(game->mlx, "assets/frog_left.xpm",
			&w, &h);
	game->frog_down = mlx_xpm_file_to_image(game->mlx, "assets/frog_down.xpm",
			&w, &h);
}

void	put_image(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	// mettre le wall sur tous les 1
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->background, y
				* 32, x * 32);
			if (game->map[x][y] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall, y
					* 32, x * 32);
			else if (game->map[x][y] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->strawberry, y * 32, x * 32);
			else if (game->map[x][y] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->end, y
					* 32, x * 32);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->frog, game->player_y
		* 32, game->player_x * 32);
	game->map[game->player_x][game->player_y] = '0';
}
