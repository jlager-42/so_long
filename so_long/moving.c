#include "so_long.h"

int	moving(t_complete *game, int i, int j)
{
	int	works;

	works = 1;
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\nYou Have Won, Congrats!\n");
		cleanup_and_exit(game);
	}
	else if (game->map[j][i] == '0' || game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		if (game->map[j][i] == 'C')
			game->collectables--;
		game->counter++;
	}
	else
		return (0);
	return (works);
}
