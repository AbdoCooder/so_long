/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:10:36 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/29 19:48:38 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	ft_check_char(t_map_data *map, int x, int y, int num)
{
	if (num == GROUND_TEXTURE)
		return (map->map[y][x] == '0' || map->map[y][x] == 'E'
				|| map->map[y][x] == 'C' || map->map[y][x] == 'P'
				|| map->map[y][x] == '1');
	if (num == WALLS_TEXTURE)
		return (map->map[y][x] == '1');
	if (num == COLECTABLES_TEXTURE)
		return (map->map[y][x] == 'C');
	if (num == EXITS_TEXTURE)
		return (map->map[y][x] == 'E');
	if (num == PLAYER_TEXTURE)
		return (map->map[y][x] == 'P');
	return (false);
}

char	*ft_write_path(t_textures *textures, int num)
{
	if (num == GROUND_TEXTURE)
		return (textures->ground_path);
	if (num == WALLS_TEXTURE)
		return (textures->walls_path);
	if (num == COLECTABLES_TEXTURE)
		return (textures->colectables_path);
	if (num == EXITS_TEXTURE)
		return (textures->exit_path_0);
	if (num == PLAYER_TEXTURE)
		return (textures->player_path);
	return (NULL);
}

bool	ft_textures_so_long(t_game *game, t_map_data *map)
{
	t_textures	textures;

	ft_fill_textures(&game, &textures);
	if (!ft_check_textures())
		return (free(game->textures),
			ft_printf("Error | Failed to load textures!\n"),
			false);
	game->mlx = mlx_init(map->width * P, map->height * P, "so_long", false);
	if (!ft_put_texture(game->mlx, map, &textures, GROUND_TEXTURE))
		return (ft_printf("Error | Failed to put the GROUND_TEXTURE!\n"), false);
	if (!ft_put_texture(game->mlx, map, &textures, WALLS_TEXTURE))
		return (ft_printf("Error | Failed to put the WALLS_TEXTURE!\n"), false);
	if (!ft_put_texture(game->mlx, map, &textures, COLECTABLES_TEXTURE))
		return (ft_printf("Error | Failed to put the COLECTABLES_TEXTURE!\n"),
			false);
	if (!ft_put_texture(game->mlx, map, &textures, EXITS_TEXTURE))
		return (ft_printf("Error | Failed to put the EXITS_TEXTURE!\n"), false);
	return (true);
}

bool	ft_init_game(t_map_data *map)
{
	t_game	game;

	if (!ft_textures_so_long(&game, map))
		return (false);
	game.map = malloc(sizeof(t_map_data));
	if (!game.map)
		return (ft_printf("Error | Failed to allocate memory for game.map!\n"),
			false);
	ft_clone_map(&game, map);
	ft_find_pos(map, &(game.player_pos), 'P');
	ft_put_player(&game);
	ft_printf("Game Start!\n");
	game.moves = 0;
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	ft_free_2d(game.map->map, game.map->height);
	free(game.textures);
	free(game.map);
	mlx_terminate(game.mlx);
	return (true);
}

void	ft_start_game(t_map_data *map)
{
	if (!ft_init_game(map))
		exit(EXIT_FAILURE);
}
