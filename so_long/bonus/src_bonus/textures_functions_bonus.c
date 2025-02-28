/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_functions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:43:17 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/29 21:25:04 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

bool	ft_put_texture(mlx_t *mlx, t_map_data *map,
						t_textures *textures, int num)
{
	int		x;
	int		y;
	void	*texture;
	void	*image;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (ft_check_char(map, x, y, num))
			{
				texture = mlx_load_png(ft_write_path(textures, num));
				image = mlx_texture_to_image(mlx, texture);
				if (mlx_image_to_window(mlx, image, x * P, y * P) == -1)
					return (false);
				mlx_delete_texture(texture);
			}
			x++;
		}
		y++;
	}
	return (true);
}

void	ft_fill_textures(t_game **game, t_textures *textures)
{
	textures->ground_path = "textures/ground.png";
	textures->walls_path = "textures/wall.png";
	textures->colectables_path = "textures/colectable.png";
	textures->exit_path_0 = "textures/exit0.png";
	textures->exit_path_1 = "textures/exit1.png";
	textures->player_path = "textures/player.png";
	textures->enemy_path = "textures/enemy.png";
	(*game)->textures = malloc(sizeof(t_textures));
	(*game)->textures->ground_path = "textures/ground.png";
	(*game)->textures->walls_path = "textures/wall.png";
	(*game)->textures->colectables_path = "textures/colectable.png";
	(*game)->textures->exit_path_0 = "textures/exit0.png";
	(*game)->textures->player_path = "textures/player.png";
	(*game)->textures->exit_path_1 = "textures/exit1.png";
	(*game)->textures->enemy_path = "textures/enemy.png";
}

void	**ft_get_textures(void **texture)
{
	texture = malloc(7 * sizeof(void *));
	texture[GROUND_TEXTURE] = mlx_load_png("textures/ground.png");
	texture[WALLS_TEXTURE] = mlx_load_png("textures/wall.png");
	texture[PLAYER_TEXTURE] = mlx_load_png("textures/player.png");
	texture[COLECTABLES_TEXTURE] = mlx_load_png("textures/colectable.png");
	texture[EXITS0_TEXTURE] = mlx_load_png("textures/exit0.png");
	texture[ENEMY_TEXTURE] = mlx_load_png("textures/enemy.png");
	texture[EXITS1_TEXTURE] = mlx_load_png("textures/exit1.png");
	return (texture);
}

void	ft_remove_textures(void **texture)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (texture[i] == NULL)
			i++;
		else
		{
			mlx_delete_texture(texture[i]);
			i++;
		}
	}
	free(texture);
	texture = NULL;
}

bool	ft_check_textures(void)
{
	void	**texture;
	int		i;

	i = 0;
	texture = NULL;
	texture = ft_get_textures(texture);
	while (i < 7)
	{
		if (texture[i] == NULL)
		{
			ft_remove_textures(texture);
			return (false);
		}
		i++;
	}
	ft_remove_textures(texture);
	return (true);
}
