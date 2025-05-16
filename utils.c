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

int	map_is_valid(t_game *game)
{
	if (is_rectangle(game) == 1)
	{
		perror("Ce n'est pas un rectangle");
		return (1);
	}
	else if (contour_map(game) == 1)
	{
		perror("Les contours de la map ne possèdent pas de '1'");
		return (1);
	}
	else if (in_map(game) == 1)
	{
		perror("E, P ou C invalide");
		return (1);
	}
	else if (path_is_valid(game) == 1)
	{
		perror("Path is not valid");
		return (1);
	}
	else
		ft_printf("La map est valide\n");
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	destroy_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->background);
	mlx_destroy_image(game->mlx, game->end);
	mlx_destroy_image(game->mlx, game->frog);
	mlx_destroy_image(game->mlx, game->frog_jump);
	mlx_destroy_image(game->mlx, game->strawberry);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->frog_left);
	mlx_destroy_image(game->mlx, game->frog_down);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;
	int		j;

	i = ft_strlen(s);
	j = 0;
	s2 = malloc(i + 1);
	if (s2 == NULL)
		return (NULL);
	while (j < i)
	{
		s2[j] = s[j];
		j++;
	}
	s2[i] = '\0';
	return (s2);
}

char	**malloc_map(char **old_map, char *line, int count)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (count + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(old_map);
	return (new_map);
}
