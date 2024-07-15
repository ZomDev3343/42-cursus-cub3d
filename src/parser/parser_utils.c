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
		if (is_color_correct(global->assets.f_color[0],
			global->assets.f_color[1], global->assets.f_color[2]) == 1)
			return (error_mess("Incorrect floor color !"));
	}
	else if (color[0] == 'C' && color[1] == '\0')
	{
		global->assets.c_color[0] = ft_atoi(split_color[0]);
		global->assets.c_color[1] = ft_atoi(split_color[1]);
		global->assets.c_color[2] = ft_atoi(split_color[2]);
		if (is_color_correct(global->assets.c_color[0],
			global->assets.c_color[1], global->assets.c_color[2]) == 1)
			return (error_mess("Incorrect ceiling color !"));
	}
	else
		return (1);
	return (0);
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
		if ((line[j] - '0') >= 0 && (line[j] - '0' <= 1))
			global->map[i][j] = line[j] - '0';
		else if (line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'E' || line[j] == 'O')
			init_player(global, line[j], i, j);
		else if (line[j] == ' ')
			global->map[i][j] = -1;
		else
			return (1);
		j++;
	}
	global->map[i][j] = -2;
	return (0);
}

/*
 * copy_assets is a function for get images assets
 *
 * return status error or succes
 * */
int	copy_assets(t_global *global, char **split_line)
{
	char	*texture_path;

	texture_path = ft_strncpy(split_line[1], ft_strchr_i(split_line[1], '\n'));
	if (ft_strcmp(split_line[0], "NO"))
		global->assets.n_texture = mlx_xpm_file_to_image(global->mlx,
				texture_path, &(global->assets.n_w), &(global->assets.n_h));
	else if (ft_strcmp(split_line[0], "SO"))
		global->assets.s_texture = mlx_xpm_file_to_image(global->mlx,
				texture_path, &(global->assets.s_w), &(global->assets.s_h));
	else if (ft_strcmp(split_line[0], "WE"))
		global->assets.w_texture = mlx_xpm_file_to_image(global->mlx,
				texture_path, &(global->assets.w_w), &(global->assets.w_h));
	else if (ft_strcmp(split_line[0], "EA"))
		global->assets.e_texture = mlx_xpm_file_to_image(global->mlx,
				texture_path, &(global->assets.e_w), &(global->assets.e_h));
	else
		return (free(texture_path), error_mess("Incorrect texture direction"));
	return (free(texture_path), 0);
}

int	must_skip_line(char *line)
{
	if (line[0] == '\n' && line[1] == '\0')
		return (free(line), 1);
	return (0);
}
