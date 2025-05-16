/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:39:46 by lbard             #+#    #+#             */
/*   Updated: 2025/05/06 02:39:46 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	move_player(t_game *game, int new_x, int new_y, void *tiles)
{
	(void)tiles;
	if (game->map[new_x][new_y] == '1')
		return ;
	if (game->map[new_x][new_y] == 'E'
		&& game->collectibles != game->total_collectibles)
		return ;
	if (game->map[new_x][new_y] == 'C')
	{
		game->collectibles++;
		game->map[new_x][new_y] = '0';
	}
	if (game->map[new_x][new_y] == 'E'
		&& game->collectibles == game->total_collectibles)
		destroy_window(game);
	game->map[game->player_x][game->player_y] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	put_image(game);
	mlx_put_image_to_window(game->mlx, game->window, tiles, game->player_y * 32,
		game->player_x * 32);
	printf("Moves: %d\n", game->moves);
}

int	keypress(int key, t_game *game)
{
	if (key == 119)
		move_player(game, game->player_x - 1, game->player_y, game->frog_jump);
	else if (key == 97)
		move_player(game, game->player_x, game->player_y - 1, game->frog_left);
	else if (key == 115)
		move_player(game, game->player_x + 1, game->player_y, game->frog_down);
	else if (key == 100)
		move_player(game, game->player_x, game->player_y + 1, game->frog);
	else if (key == 65307)
		destroy_window(game);
	return (0);
}