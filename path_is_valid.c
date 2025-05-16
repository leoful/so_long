/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:51:41 by lbard             #+#    #+#             */
/*   Updated: 2025/05/16 02:41:34 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_copy)
		return (NULL);
	while (i < game->map_height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	check_C_and_E(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	path_is_valid(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player_x, game->player_y);
	if (check_C_and_E(map_copy))
	{
		free_map(map_copy);
		return (1);
	}
	free_map(map_copy);
	return (0);
}
