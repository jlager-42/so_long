#include "so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	cleanup_and_exit(t_complete *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		// mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_complete));
	read_map(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 40),
		(game.heightmap * 40), "solong");
	// find_graphics(&game);
	// place_graphics(&game);
	// // mlx_key_hook(game.winpointer, controls_working, &game);
	// // mlx_hook(game.winpointer, 17, 0, cleanup_and_exit, &game);
	// // mlx_loop(game.mlxpointer);
}