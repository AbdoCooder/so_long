/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:34:22 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/29 21:06:07 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

bool	ft_check_rectangular(t_map_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		if (ft_strlen_gnl(map->map[i] + j, '\n') != map->width)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_first_last_line(t_map_data *map)
{
	int	j;

	j = 0;
	while (j < map->width)
	{
		if (map->map[0][j] != '1')
			return (false);
		j++;
	}
	j = 0;
	while (j < map->width)
	{
		if (map->map[map->height - 1][j] != '1')
			return (false);
		j++;
	}
	return (true);
}

bool	ft_check_barriers(t_map_data *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1')
			return (false);
		if (map->map[i][map->width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_walls(t_map_data *map)
{
	if (!ft_check_first_last_line(map))
		return (false);
	if (!ft_check_barriers(map))
		return (false);
	return (true);
}

bool	ft_check_chars(t_map_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width - 1)
		{
			if (map->map[i][j] != '1'
				&& map->map[i][j] != '0'
				&& map->map[i][j] != 'P'
				&& map->map[i][j] != 'E'
				&& map->map[i][j] != 'M'
				&& map->map[i][j] != 'C')
			{
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
