#include "so_long.h"

static int	keyboard_w(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	j--;
	if (game->map[j][i] == '1')
		return (0);
	k = moveing(game, i, j);
	if (!k)
		return (0);
	game->map[j + 1][i] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_s(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	j++;
	if (game->map[j][i] == '1')
		return (0);
	k = moveing(game, i, j);
	if (!k)
		return (0);
	game->map[j - 1][i] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_a(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	i--;
	if (game->map[j][i] == '1')
		return (0);
	k = moveing(game, i, j);
	if (!k)
		return (0);
	game->map[j][i + 1] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_d(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	i++;
	if (game->map[j][i] == '1')
		return (0);
	k = moveing(game, i, j);
	if (!k)
		return (0);
	game->map[j][i - 1] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

int	command_key(int command, t_complete *game)
{
	int	works = 0;

	if (command == 53)
		cleanup_and_exit(game);
	else if (command == 13)
		works = keyboard_w(game, command);
	else if (command == 1)
		works = keyboard_s(game, command);
	else if (command == 0)
		works = keyboard_a(game);
	else if (command == 2)
		works = keyboard_d(game);
	if (works)
		place_graphics(game);
	return (1);
}