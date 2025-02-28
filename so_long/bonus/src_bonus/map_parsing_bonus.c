/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:13:19 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/29 21:45:35 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	ft_read_lines(char *line, t_map_data *map, int fd)
{
	while (line != NULL)
	{
		map->map[map->height] = line;
		map->height++;
		if (map->width == 0)
			map->width = ft_strlen(line) - 1;
		line = get_next_line(fd);
	}
}

void	ft_read_map(t_map_data *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR\nFAILED TO OPEN THE MAP FILE (%s)\n", file);
		exit(1);
	}
	map->map = (char **)malloc(sizeof(char *) * 100);
	if (!map->map)
	{
		close(fd);
		ft_error("ERROR\nMemory allocation failed\n");
	}
	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	ft_read_lines(line, map, fd);
	close(fd);
}

void	free_map(t_map_data *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->map[i++]);
	free(map->map);
}

void	ft_calculate_elements(t_map_data *map)
{
	int	i;
	int	j;

	i = 0;
	map->players = 0;
	map->col = 0;
	map->exits = 0;
	map->enemies = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				map->players++;
			else if (map->map[i][j] == 'C')
				map->col++;
			else if (map->map[i][j] == 'E')
				map->exits++;
			else if (map->map[i][j] == 'M')
				map->enemies++;
			j++;
		}
		i++;
	}
}
