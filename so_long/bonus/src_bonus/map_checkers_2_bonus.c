/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:31:37 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/29 21:04:32 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

bool	ft_check_requirements(t_map_data *map)
{
	ft_calculate_elements(map);
	if (map->players != 1)
		return (ft_map_errors(ERROR_INVALID_NUMBER_OF_PLAYERS), false);
	if (map->col < 1)
		return (ft_map_errors(ERROR_INVALID_NUMBER_OF_COLLECTIBLES), false);
	if (map->enemies < 1)
		return (ft_map_errors(ERROR_INVALID_NUMBER_OF_ENEMIES), false);
	if (map->exits != 1)
		return (ft_map_errors(ERROR_INVALID_NUMBER_OF_EXITS), false);
	return (true);
}

bool	ft_check_flood(char **map_copy, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_check_path(t_map_data *map)
{
	char	**map_copy;
	t_pos	player;

	map_copy = ft_strdup_2d(map->map, map->height);
	if (!map_copy)
		return (false);
	ft_find_pos(map, &player, 'P');
	flood_fill(map_copy, player.x, player.y);
	if (!ft_check_flood(map_copy, map->height, map->width))
	{
		ft_free_2d(map_copy, map->height);
		return (false);
	}
	ft_free_2d(map_copy, map->height);
	return (true);
}

void	ft_free_2d(char **array, int height)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (i < height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

bool	ft_validate_map(t_map_data *map)
{
	if (map->height > MAX_HEIGHT || map->width > MAX_WIDTH)
		return (ft_map_errors(ERROR_SIZE_MAP), false);
	if (!ft_check_rectangular(map))
		return (ft_map_errors(ERROR_MAP_NOT_RECTANGULAR), false);
	if (!ft_check_walls(map))
		return (ft_map_errors(ERROR_MAP_NOT_SURROUNDED_BY_WALLS), false);
	if (!ft_check_chars(map))
		return (ft_map_errors(ERROR_INVALID_CHARACTER), false);
	if (!ft_check_requirements(map))
		return (false);
	if (!ft_check_path(map))
		return (ft_map_errors(ERROR_NO_VALID_PATH), false);
	return (true);
}
