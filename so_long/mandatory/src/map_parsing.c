/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:13:19 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/29 19:52:54 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	ft_map_errors(int error)
{
	if (error == ERROR_MAP_NOT_RECTANGULAR)
		ft_printf("Error\nMap is not rectangular.\n");
	else if (error == ERROR_MAP_NOT_SURROUNDED_BY_WALLS)
		ft_printf("Error\nMap is not surrounded by walls.\n");
	else if (error == ERROR_INVALID_NUMBER_OF_PLAYERS)
		ft_printf("Error\nInvalid number of players (P).\
		(Hint: Only one starting position)\n");
	else if (error == ERROR_INVALID_NUMBER_OF_EXITS)
		ft_printf("Error\nInvalid number of exits (E). (Hint: Only one exit)\n");
	else if (error == ERROR_INVALID_NUMBER_OF_COLLECTIBLES)
		ft_printf("Error\nInvalid number of collectibles (C).\
		(Hint: At least one collectibles)\n");
	else if (error == ERROR_INVALID_CHARACTER)
		ft_printf("Error\nInvalid character in map.\
		(Hint: Valide chars [0, 1, P, C, E])\n");
	else if (error == ERROR_NO_VALID_PATH)
		ft_printf("Error\nNo valid path to exit or collectibles.\n");
	else if (error == ERROR_MAP_FILE_EMPTY)
		ft_printf("Error\nMap file is empty.\n");
	else if (error == ERROR_FAILED_TO_OPEN_MAP_FILE)
		ft_printf("Error\nFailed to open map file.\n");
	else if (error == ERROR_INVALID_FILE_EXTENTION)
		ft_printf("Error\nInvalid file extention.\n");
	else if (error == ERROR_SIZE_MAP)
		ft_printf("Error\nThe map is too big.\n");
	else
		ft_printf("Error\nUnknown error.\n");
}

void	ft_calculate_elements(t_map_data *map)
{
	int	i;
	int	j;

	i = 0;
	map->players = 0;
	map->col = 0;
	map->exits = 0;
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
			j++;
		}
		i++;
	}
}
