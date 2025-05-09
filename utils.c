/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:31:16 by lbard             #+#    #+#             */
/*   Updated: 2025/05/06 01:31:16 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_is_valide(t_game *game)
{
    if (is_rectangle(game) == 1)
        perror("Ce n'est pas un rectangle");
    else if (contour_map(game) == 1)
        perror("Les contours de la map ne possèdent pas de '1'");
    else if (in_map(game) == 1)
        perror("E, P ou C invalide");
    else 
        ft_printf("La map est valide");
    return (0);
}

int free_game_map(t_game *game)
{
    int i;

    i = 0;
    while (game->map[i])
    {
        free(game->map[i]);
    }
    free(game->map[i]);
    return (0);
}

int destroy_window(t_game *game)
{
    mlx_destroy_image(game->mlx, game->knight);
    mlx_destroy_image(game->mlx, game->knight_down);
    mlx_destroy_image(game->mlx, game->knight_hit);
    mlx_destroy_image(game->mlx, game->dirt);
    mlx_destroy_image(game->mlx, game->coins);
    mlx_destroy_image(game->mlx, game->sky);
    mlx_destroy_image(game->mlx, game->slime);
    mlx_destroy_image(game->mlx, game->wall);
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
    return (0);
}