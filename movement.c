/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:39:46 by lbard             #+#    #+#             */
/*   Updated: 2025/05/06 02:39:46 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void start_position(t_game *game)
{
    int x;
    int y;

    x = 0;
    while(game->map[x])
    {
        y = 0;
        while (game->map[x][y])
        {
            if (game->map[x][y] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
            }
            y++;
        }
        x++;
    }
}