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

void    load_images(t_game *game)
{
    int w;
    int h;

    //game->knight = mlx_xpm_file_to_image(game->mlx, "assets/knight.xpm", &w, &h);
   // game->knight_down = mlx_xpm_file_to_image(game->mlx, "assets/knight_down.xpm", &w, &h);
    //game->knight_hit = mlx_xpm_file_to_image(game->mlx, "assets/knight_hit.xpm", &w, &h);
    game->dirt = mlx_xpm_file_to_image(game->mlx, "assets/dirt.xpm", &w, &h);
    game->coins = mlx_xpm_file_to_image(game->mlx, "assets/coins.xpm", &w, &h);
    game->sky = mlx_xpm_file_to_image(game->mlx, "assets/sky.xpm", &w, &h);
    //game->slime = mlx_xpm_file_to_image(game->mlx, "assets/slime.xpm", &w, &h);
    game->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w, &h);

}

void    put_image(t_game *game)
{
    int x;
    int y;

    x = 0;
    //mettre le wall sur tous les 1
    while (game->map[x])
    {
        y = 0;
        while (game->map[x][y])
        {
            mlx_put_image_to_window(game->mlx, game->window, game->sky, y * 16, x * 16);
            if (game->map[x][y] == '1')
                mlx_put_image_to_window(game->mlx, game->window, game->wall, y * 16, x * 16);
            else if (game->map[x][y] == '2')
                mlx_put_image_to_window(game->mlx, game->window, game->dirt, y * 16, x * 16);
            else if (game->map[x][y] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->coins, y * 16, x * 16);
            y++;
        }
        x++;
    }
    //mettre la dirt sur tous les 2
    //mettre les coins sur tous les C
    //mettre le knigth sur le P
    //remplacer le knith hit si jamais (je pense quil faut faire une fonction quand le joueur est sur les coordones du mob)
    //remplacer le knigth quand le joueur appuis sur S(je pense pas dans cette fonction)
    // mettre le sky, sur touts les 0 et aussi en arriere plan du knigth et des mobs

}
