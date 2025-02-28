/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:08:13 by yagame            #+#    #+#             */
/*   Updated: 2025/01/29 19:15:24 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *str)
{
	if (str)
		ft_printf("%s", str);
	exit(1);
}

void	my_put_player(t_game *game, char *path, int x, int y)
{
	void	*texture;

	mlx_delete_image(game->mlx, game->img.player_image);
	texture = mlx_load_png(path);
	game->img.player_image = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img.player_image, x, y);
	mlx_delete_texture(texture);
}

void	ft_open_door(t_game *game, mlx_t *mlx)
{
	void	*texture;
	void	*img;
	int		i;
	int		len;

	i = 0;
	while (game->map->map[i])
	{
		len = 0;
		while (game->map->map[i][len])
		{
			if (game->map->map[i][len] == 'E')
			{
				texture = mlx_load_png("textures/exit1.png");
				img = mlx_texture_to_image(mlx, texture);
				mlx_image_to_window(mlx, img, len * P, i * P);
				mlx_delete_texture(texture);
				return ;
			}
			len++;
		}
		i++;
	}
}

void	ft_clone_map(t_game *game, t_map_data *map)
{
	game->map->col = map->col;
	game->map->exits = map->exits;
	game->map->height = map->height;
	game->map->players = game->map->players;
	game->map->map = ft_strdup_2d(map->map, map->height);
	game->map->valid = true;
	game->map->width = map->width;
}

void	ft_put_player(t_game *game)
{
	void		*t;

	t = mlx_load_png(game->textures->player_path);
	game->img.player_image = mlx_texture_to_image(game->mlx, t);
	mlx_image_to_window(game->mlx, game->img.player_image,
		game->player_pos.x * 64, game->player_pos.y * 64);
	mlx_delete_texture(t);
}
