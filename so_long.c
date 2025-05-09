/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:31:42 by lbard             #+#    #+#             */
/*   Updated: 2025/05/06 01:31:42 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int init_game(t_game *game)
{
    game->map = NULL;
    game->count = 0;
    game->mlx = mlx_init();
    if (!game->mlx) 
    {
        ft_printf("Failed to initialize MiniLibX.\n");
        return (1);
    }
    // Crée une fenêtre avec une largeur de 1920, une hauteur de 1080 et un titre.
    game->window = mlx_new_window(game->mlx, 1920, 1080, "so_long");
    if (!game->window) 
    {
        ft_printf("Failed to create window.\n");
        free(game->mlx);
        return (1);
    }
    return (0);
}

int main(void)
{
    t_game game;

    // Initialisation des composants du jeu
    if (init_game(&game)) 
        return (1);
    if (ft_parsing_map(&game, "map.ber") != 0) 
    {
        ft_printf("Erreur lors du parsing de la carte");
        return (1);
    }
    map_is_valide(&game);
    load_images(&game);
    put_image(&game);
    mlx_loop(game.mlx);  // Démarre la boucle principale de MiniLibX
    free_game_map(&game);
    return (0);
}