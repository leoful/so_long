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
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdio.h>  // Fonctions : printf, perror
# include <stdlib.h> // Fonctions : malloc, free
# include <unistd.h> // Fonctions : write, close, etc.

// inclure ft_printf et gnl
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		map_width;
	int		map_height;

	char	**map;
	int		player_x;
	int		player_y;
	int		moves;
	int		count;
	int		collectibles;
	int		total_collectibles;

	void	*background;
	void	*end;
	void	*frog;
	void	*frog_jump;
	void	*frog_left;
	void	*frog_down;
	void	*strawberry;
	void	*wall;
}			t_game;

void		init_struc(t_game *game);
int			init_game(t_game *game);
int			ft_parsing_map(t_game *game, char *map_file);
int			is_rectangle(t_game *game);
int			contour_map(t_game *game);
int			in_map(t_game *game);
int			map_is_valid(t_game *game);
void		free_map(char **map);
void		load_images(t_game *game);
void		put_image(t_game *game);
void		start_position(t_game *game);
void		move_player(t_game *game, int new_x, int new_y, void *tiles);
int			keypress(int key, t_game *game);
int			destroy_window(t_game *game);
void		apply_gravity(t_game *game, void *sprite);
char		*ft_strdup(const char *s);
int			path_is_valid(t_game *game);
char		**malloc_map(char **old_map, char *line, int count);

#endif