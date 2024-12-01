#include "so_long.h"

void	find_graphics(t_complete *game)
{
	int	i;
	int	j;
	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"so_long_graphics/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"so_long_graphics/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"so_long_graphics/player_right.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"so_long_graphics/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"so_long_graphics/collectable.xpm", &i, &j);
}

static void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 32, height * 32);
	game->collectables++;
}

static void	place_exit(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->exit, width * 32, height * 32);
	game->exit++;
}

static void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 32, height * 32);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->floor, width * 32, height * 32);
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer, game->barrier, width * 32, height * 32);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'E')
				place_exit(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			width++;
		}
		height++;
	}
}