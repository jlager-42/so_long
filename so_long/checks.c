# include "so_long.h"

// comment :) delete me
static void	check_count(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '0' &&
		game->map[height][width] != '1' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != '\n')
	{
		ft_printf("\nError: Invalid character '%c' found in map\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
			game->collectiblecount++;
	if (game->map[height][width] == 'E')
			game->exitcount++;
	if (game->map[height][width] == 'P')
			game->playercount++;
}

static void	check_characters(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width < game->widthmap)
		{
			check_count(game, height, width);
			width++;
		}
		height++;
	}
	if (game->collectiblecount < 1 ||
		game->exitcount != 1 ||
		game->playercount != 1)
	{
		ft_printf("\nError: Invalid map configuration
			\neither Player, Exit or Collectable issue\n");
		exit_point(game);
	}
}

static int	check_horizontal_walls(t_complete *game)
{
	int	width;

	width = 0;
	while (width < game->widthmap)
	{
		if (game->map[0][width] != '1' || game->map[game->heightmap - 1][width] != '1')
			ft_printf("\nError: Horizontal wall incomplete\n")
			return (0);
		width++;
	}
	return (1);
}

static int	check_vertical_walls(t_complete *game)
{
	int	height;

	height = 0;
	while (height < game->heightmap)
	{
		if (game->map[height][0] != '1' || game->map[height][game->widthmap - 1] != '1')
			ft_printf("\nError: Verticl wall incomplete\n")
			return (0);
		height++;
	}
	return (1);
}

void	check_errors(t_complete *game)
{
	int	vertical_walls;
	int	horizontal_walls;

	vertical_walls = check_vertical_walls(game);
	horizontal_walls = check_horizontal_walls(game);
	if (vertical_walls != 1 || horizontal_walls != 1)
	{
		ft_printf("\nError: The map is missing walls\n");
		exit_point(game);
	}
	check_characters(game);
}