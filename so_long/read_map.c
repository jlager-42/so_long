#include "so_long.h"

static int	get_map_width(char *map)
{
	int	width;

	width = 0;
	while (map[width] != '\0' && map[width] != '\n')
		width++;
	return (width);
}

static int	append_line_to_map(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!temporary)
		return (0);
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	if (game->map != NULL)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	read_map(t_complete *game, char **argv)
{
    char	*readmap;

    game->fd = open(argv[1], O_RDONLY);
    if (game->fd < 0)
        return (0);
    while ((readmap = get_next_line(game->fd)) != NULL)
    {
        if (!append_line_to_map(game, readmap))
        {
            free(readmap);
            close(game->fd);
            return (0);
        }
        free(readmap);
    }
    if (close(game->fd) < 0)
        return (0);
    if (game->map != NULL && game->map[0] != NULL)
        game->widthmap = get_map_width(game->map[0]);
    else
        game->widthmap = 0;
    return (1);
}