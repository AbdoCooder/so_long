/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:21:09 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/29 19:48:16 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	take_coin(t_game *game, int x, int y)
{
	void	*texture;
	void	*img;

	ft_printf("move: %d\n", game->moves++);
	if (game->map->map[y][x] == 'C')
	{
		game->map->col -= 1;
		game->map->map[y][x] = '0';
		texture = mlx_load_png("textures/ground.png");
		img = mlx_texture_to_image(game->mlx, texture);
		mlx_image_to_window(game->mlx, img, x * P, y * P);
		mlx_delete_texture(texture);
		if (game->map->col == 0)
			ft_open_door(game, game->mlx);
		mlx_image_to_window(game->mlx, game->img.player_image, x * P, y * P);
	}
	else if (game->map->map[y][x] == 'E' && game->map->col == 0)
	{
		ft_free_2d(game->map->map, game->map->height);
		free(game->map);
		free(game->textures);
		mlx_terminate(game->mlx);
		ft_printf("Congratulation! You found your exit\n");
		exit(EXIT_SUCCESS);
	}
}

bool	ft_check_x_y(t_game *game, int x, int y)
{
	char	**ptr;

	ptr = game->map->map;
	return (ptr[y][x] == '0' || ptr[y][x] == 'C' ||
			ptr[y][x] == 'P' || (ptr[y][x] == 'E' &&
			game->map->col == 0));
}

void	horizontal(mlx_key_data_t keydata, t_game *game, int x, int y)
{
	char	**ptr;

	ptr = game->map->map;
	if (keydata.key == MLX_KEY_LEFT && keydata.action && ptr[y][x - 1] != '1')
	{
		if (ft_check_x_y(game, x - 1, y))
		{
			game->img.player_image->instances->x -= P;
			my_put_player(game, game->textures->player_path,
				(x - 1) * P, y * P);
			take_coin(game, x - 1, y);
		}
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action
		&& ptr[y][x + 1] != '1')
	{
		if (ft_check_x_y(game, x + 1, y))
		{
			game->img.player_image->instances->x += P;
			my_put_player(game, game->textures->player_path,
				(x + 1) * P, y * P);
			take_coin(game, x + 1, y);
		}
	}
}

void	vertical(mlx_key_data_t keydata, t_game *game, int x, int y)
{
	char	**ptr;

	ptr = game->map->map;
	if (keydata.key == MLX_KEY_UP && keydata.action && ptr[y - 1][x] != '1')
	{
		if (ft_check_x_y(game, x, y - 1))
		{
			game->img.player_image->instances->y -= P;
			my_put_player(game, game->textures->player_path,
				(x) * P, (y -1) * P);
			take_coin(game, x, y - 1);
		}
	}
	else if (keydata.key == MLX_KEY_DOWN
		&& keydata.action && ptr[y + 1][x] != '1')
	{
		if (ft_check_x_y(game, x, y + 1))
		{
			game->img.player_image->instances->y += P;
			my_put_player(game, game->textures->player_path,
				(x) * P, (y + 1) * P);
			take_coin(game, x, y + 1);
		}
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	x = game->img.player_image->instances->x / P;
	y = game->img.player_image->instances->y / P;
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		horizontal(keydata, game, x, y);
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
		vertical(keydata, game, x, y);
	else if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}
