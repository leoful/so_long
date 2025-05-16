/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:31:42 by lbard             #+#    #+#             */
/*   Updated: 2025/05/16 03:03:21 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->map = NULL;
	game->count = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->total_collectibles = 0;
	game->moves = 0;
	game->background = NULL;
	game->wall = NULL;
	game->strawberry = NULL;
	game->end = NULL;
	game->frog = NULL;
	game->frog_jump = NULL;
}

int	init_game(t_game *game)
{
	int	w_window;
	int	h_window;

	w_window = game->map_width * 32;
	h_window = game->map_height * 32;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Failed to initialize MiniLibX.\n");
		return (1);
	}
	/*Crée une fenêtre avec une largeur de 1920, une hauteur de 1080 et un titre.*/
	game->window = mlx_new_window(game->mlx, w_window, h_window, "so_long");
	if (!game->window)
	{
		ft_printf("Failed to create window.\n");
		free(game->mlx);
		return (1);
	}
	return (0);
}

int	main(void)
{
	t_game game;

	/*initialisation des composants du jeu*/
	init_struct(&game);
	if (ft_parsing_map(&game, "map.ber") != 0)
	{
		ft_printf("Erreur lors du parsing de la carte");
		return (1);
	}
	if (init_game(&game))
		return (1);
	start_position(&game);
	if (map_is_valid(&game))
	{
		destroy_window(&game);
		return (1);
	}
	load_images(&game);
	put_image(&game);
	mlx_hook(game.window, 17, 0, destroy_window, &game);
	mlx_key_hook(game.window, keypress, &game);
	mlx_loop(game.mlx); /*démarre la boucle principale de MiniLibX */
	free_map(game.map);
	return (0);
}