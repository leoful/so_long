/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:24:39 by lbard             #+#    #+#             */
/*   Updated: 2024/12/16 17:24:39 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <unistd.h>   // Fonctions : write, close, etc.
#include <stdlib.h>  // Fonctions : malloc, free
#include <stdio.h>    // Fonctions : printf, perror
#include <X11/X.h>
#include <X11/keysym.h>

// inclure ft_printf et gnl
#include "printf/ft_printf.h"
#include "gnl/get_next_line.h"

typedef struct s_game
{
    void    *mlx;
    void    *window;

    char    **map;
    int     player_x;
    int     player_y;
    int     moves;
    int     count;

    void    *knight;
    void    *knight_down;
    void    *knight_hit;
    void    *slime;
    void    *coins;
    void    *wall;
    void    *sky;
    void    *dirt;
} t_game;

int init_game(t_game *game);
int ft_parsing_map(t_game *game, char *map_file);
int is_rectangle(t_game *game);
int contour_map(t_game *game);
int in_map(t_game *game);
int map_is_valide(t_game *game);
int free_game_map(t_game *game);
void    load_images(t_game *game);
void    put_image(t_game *game);

#endif