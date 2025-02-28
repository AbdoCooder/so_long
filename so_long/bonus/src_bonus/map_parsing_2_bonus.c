/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:45:25 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/29 21:46:25 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	ft_continue(int error)
{
	if (error == ERROR_INVALID_CHARACTER)
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
	else if (error == ERROR_INVALID_NUMBER_OF_ENEMIES)
		ft_printf("Error\nInvalid number of enemies (M). \
		(Hint: Enemy required)\n");
	else if (error == ERROR_INVALID_NUMBER_OF_COLLECTIBLES)
		ft_printf("Error\nInvalid number of collectibles (C).\
		(Hint: At least one collectibles)\n");
	else
		ft_continue(error);
}

bool	ft_check_x_y(t_game *game, int x, int y)
{
	char	**ptr;

	ptr = game->map->map;
	return (ptr[y][x] == '0' || ptr[y][x] == 'M' ||
			ptr[y][x] == 'C' || ptr[y][x] == 'P' ||
			(ptr[y][x] == 'E' && game->map->col == 0));
}
