/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbard <lbard@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:22:45 by lbard             #+#    #+#             */
/*   Updated: 2025/05/16 03:03:13 by lbard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// lire les lignes de la map et les stocker dans ma structure
int	ft_parsing_map(t_game *game, char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (1);
	game->map = NULL;
	game->count = 0;
	while ((line = get_next_line(fd)))
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map = malloc_map(game->map, line, game->count);
		if (!game->map)
			return (1);
		game->count++;
	}
	game->map_height = game->count;
	game->map_width = ft_strlen(game->map[0]);
	close(fd);
	return (0);
}

// verifier que la map respecte une forme rectangulaire
int	is_rectangle(t_game *game)
{
	int	column;
	int	line;
	int	verifline;

	column = 0;
	line = 0;
	verifline = 0;
	// verifier si les colonne sont plus grandes que les lignes
	while (game->map[0][column])
		column++;
	while (line < game->count)
	{
		verifline = ft_strlen(game->map[line]);
		if (verifline != column)
			return (1);
		line++;
	}
	return (0);
}
// verifier que la map est encadree de mur
int	contour_map(t_game *game)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	// verifier le bords haut de la map
	while (column < game->map_width)
	{
		if (game->map[0][column] != '1')
			return (1);
		column++;
	}
	column = 0;
	// Bord inférieur
	while (column < game->map_width)
	{
		if (game->map[game->count - 1][column] != '1')
			return (1);
		column++;
	}
	// verifier les bords gauche et droit de la map
	while (line < game->count)
	{
		if (game->map[line][0] != '1')
			return (1);
		if (game->map[line][game->map_width - 1] != '1')
			return (1);
		line++;
	}
	return (0);
}

// verifier que la map contient un seul E, un seul P, et au moins un C
// verifier que le joueur peut atteindre tout les C et E(surement en verifiant si un 1 qui bloc C ou E)

int	in_map(t_game *game)
{
	int	line;
	int	column;
	int	count_e;
	int	count_p;

	line = 0;
	count_e = 0;
	count_p = 0;
	while (game->map[line])
	{
		column = 0;
		while (game->map[line][column])
		{
			if (game->map[line][column] == 'E')
				count_e++;
			if (game->map[line][column] == 'P')
				count_p++;
			if (game->map[line][column] == 'C')
				game->total_collectibles++;
			column++;
		}
		line++;
	}
	if (count_e != 1 || count_p != 1 || game->total_collectibles == 0)
		return (1);
	return (0);
}
