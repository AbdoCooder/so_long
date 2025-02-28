/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:33:44 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/26 17:21:54 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_strdup_2d(char **strs, int height)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(strs[i]);
		i++;
	}
	return (copy);
}

void	ft_find_pos(t_map_data *map, t_pos *position, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == c)
			{
				position->x = j;
				position->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map_copy, int x, int y)
{
	if (map_copy[y][x] == '1')
		return ;
	if (map_copy[y][x] == '0' || map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
		map_copy[y][x] = '1';
	flood_fill(map_copy, x + 1, y);
	flood_fill(map_copy, x - 1, y);
	flood_fill(map_copy, x, y + 1);
	flood_fill(map_copy, x, y - 1);
}
