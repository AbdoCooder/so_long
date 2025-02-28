/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:34:15 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/30 17:55:55 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../mandatory/lib/MLX42/include/MLX42/MLX42.h"
# include "../../mandatory/ft_printf/ft_printf.h"
# include "../../mandatory/libft/libft.h"
# include "../../mandatory/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# define MAX_WIDTH 40
# define MAX_HEIGHT 20
# define ERROR_MAP_NOT_RECTANGULAR 1
# define ERROR_MAP_NOT_SURROUNDED_BY_WALLS 2
# define ERROR_INVALID_FILE_EXTENTION 10
# define ERROR_INVALID_NUMBER_OF_PLAYERS 3
# define ERROR_INVALID_NUMBER_OF_EXITS 4
# define ERROR_INVALID_NUMBER_OF_COLLECTIBLES 5
# define ERROR_INVALID_CHARACTER 6
# define ERROR_NO_VALID_PATH 7
# define ERROR_MAP_FILE_EMPTY 8
# define ERROR_FAILED_TO_OPEN_MAP_FILE 9
# define ERROR_SIZE_MAP 11
# define ERROR_INVALID_NUMBER_OF_ENEMIES 12
# define P 64

//TEXTURES
# define GROUND_TEXTURE 0
# define WALLS_TEXTURE 1
# define PLAYER_TEXTURE 2
# define COLECTABLES_TEXTURE 3
# define EXITS0_TEXTURE 4
# define ENEMY_TEXTURE 5
# define EXITS1_TEXTURE 6

typedef struct s_map_data
{
	char	**map;
	int		height;
	int		width;
	int		players;
	int		enemies;
	int		col;
	int		exits;
	bool	valid;
}			t_map_data;

typedef struct s_textures
{
	char	*ground_path;
	char	*walls_path;
	char	*colectables_path;
	char	*exit_path_0;
	char	*exit_path_1;
	char	*player_path;
	char	*enemy_path;
}			t_textures;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_images
{
	mlx_image_t	*player_image;
	mlx_image_t	*move_image;
	mlx_image_t	*enemy_image;
	mlx_image_t	*wall_image;
	mlx_image_t	*collectable_image;
	mlx_image_t	*exit_image;
}				t_images;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map_data	*map;
	t_images	img;
	t_pos		player_pos;
	t_textures	*textures;
	int			moves;
}				t_game;

//MAP FUNCTIONS START--------------------------------------------
void	ft_open_door(t_game *game, mlx_t *mlx);
void	my_put_player(t_game *game, char *str, int x, int y);
void	my_keyhook(mlx_key_data_t keydata, void *param);

void	print_map(t_map_data *map_data);
void	ft_map_errors(int error);
void	ft_continue(int error);
void	free_map(t_map_data *map);
void	ft_read_map(t_map_data *map, char *file);
bool	ft_validate_map(t_map_data *map_data);
bool	ft_check_rectangular(t_map_data *map);
bool	ft_check_first_last_line(t_map_data *map);
bool	ft_check_barriers(t_map_data *map);
bool	ft_check_walls(t_map_data *map);
bool	ft_check_char(t_map_data *map, int x, int y, int num);
bool	ft_check_chars(t_map_data *map);
char	*ft_write_path(t_textures *textures, int num);
void	ft_calculate_elements(t_map_data *map);
bool	ft_check_requirements(t_map_data *map);
char	**ft_strdup_2d(char **strs, int height);
void	ft_find_pos(t_map_data *map, t_pos *position, char c);
void	flood_fill(char **map_copy, int x, int y);
bool	ft_check_flood(char **map_copy, int height, int width);
void	ft_free_2d(char **array, int height);
bool	ft_check_path(t_map_data *map);
bool	ft_validate_map(t_map_data *map);
//MAP FUNCTIONS END----------------------------------------------

void	ft_print_moves(t_game *game);
void	ft_error(char *str);
void	ft_start_game(t_map_data *map);
bool	ft_init_game(t_map_data *map);

//Textures
bool	ft_put_texture(mlx_t *mlx, t_map_data *map,
			t_textures *textures, int num);
void	ft_fill_textures(t_game **game, t_textures *textures);
void	**ft_get_textures(void **texture);
void	ft_remove_textures(void **texture);
bool	ft_check_textures(void);
void	ft_clone_map(t_game *game, t_map_data *map);
void	ft_put_player(t_game *game);
bool	ft_check_x_y(t_game *game, int x, int y);
#endif // SO_LONG_H
