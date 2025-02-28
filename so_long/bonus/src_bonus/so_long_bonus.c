/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:06:55 by codespace         #+#    #+#             */
/*   Updated: 2025/01/30 17:55:41 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	ft_print_moves(t_game *game)
{
	char	*move;
	int		x;
	int		y;

	x = 0;
	y = 0;
	move = ft_itoa(game->moves++);
	mlx_delete_image(game->mlx, game->img.move_image);
	game->img.move_image = mlx_new_image(game->mlx, P, P);
	while (y < P / 2)
	{
		x = 0;
		while (x < P)
		{
			mlx_put_pixel(game->img.move_image, x, y, 0xFF);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->img.move_image, 0, 0);
	game->img.move_image = mlx_put_string(game->mlx, move, 10, 5);
	free(move);
}

void	print_map(t_map_data *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->height)
	{
		ft_printf("%s", map_data->map[i]);
		i++;
	}
}

bool	ft_check_extention(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 5)
		return (false);
	if (file[i - 1] != 'r' || file[i - 2] != 'e'
		|| file[i - 3] != 'b' || file[i - 4] != '.')
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_map_data	map_data;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map.ber>\n", argv[0]);
		return (1);
	}
	if (!ft_check_extention(argv[1]))
		return (ft_map_errors(ERROR_INVALID_FILE_EXTENTION), false);
	ft_read_map(&map_data, argv[1]);
	if (map_data.height == 0)
		return (ft_map_errors(ERROR_MAP_FILE_EMPTY), free_map(&map_data), 1);
	if (!ft_validate_map(&map_data))
		return (free_map(&map_data), 1);
	ft_start_game(&map_data);
	free_map(&map_data);
	ft_printf("Game ended!\n");
	return (0);
}
