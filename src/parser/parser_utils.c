#include "../../include/cub3d.h"

/*
 * copy_color get the int value of RGB color
 *
 * return status error or succes
 * */
int	copy_color(t_global *global, char **split_color, char *color)
{
	if (color[0] == 'F' && color[1] == '\0')
	{
		global->assets.f_color[0] = ft_atoi(split_color[0]);
		global->assets.f_color[1] = ft_atoi(split_color[1]);
		global->assets.f_color[2] = ft_atoi(split_color[2]);
	}
	else if (color[0] == 'C' && color[1] == '\0')
	{
		global->assets.c_color[0] = ft_atoi(split_color[0]);
		global->assets.c_color[1] = ft_atoi(split_color[1]);
		global->assets.c_color[2] = ft_atoi(split_color[2]);
	}
	return (0);
}

/*
 * init_player init the entity player (struct)
 *
 * return status error or succes
 * */
void	init_player(t_global *global, char direction, int y, int x)
{
	(void) direction;
	global->player.x = (float) x;
	global->player.y = (float) y;
}

/*
 * copy_line_map transform and copy the char *line in int *tab
 *
 * return status error or succes
 * */
int	copy_line_map(t_global *global, int i, char *line)
{
	int	j;

	j = 0;
	while (line[j + 1])
	{
		if ((line[j] - '0') >= 0 && (line[j] - '0' <= 9))
			global->map[i][j] = line[j] - '0';
		else if (line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'E' || line[j] == 'O')
			init_player(global, line[j], i, j);
		else
			global->map[i][j] = -1;
		j++;
	}
	global->map[i][j] = -2;
	return (0);
}
