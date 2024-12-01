#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include "mlx_int.h"
# include "mlx.h"

// enum e_keycodes
// {
// 	KEY_ESC = 53,
// 	KEY_A = 0,
// 	KEY_W = 13,
// 	KEY_S = 1,
// 	KEY_D = 2
// };

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		collectiblecount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;
	char	**map;
	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

int		read_map(t_complete *game, char **argv);
void	check_errors(t_complete *game);
void	find_graphics(t_complete *game);
void	place_graphics(t_complete *game);
int		command_key(int command, t_complete *game)
int		cleanup_and_exit(t_complete *game)
int		moveing(t_complete *game, int i, int j)


#endif

