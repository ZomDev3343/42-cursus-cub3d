#include "../../include/cub3d.h"

/*
 * parse_map_assets a function to get in matrice all texture .xmp
 *
 * return status error or succes
 * */
int	parse_map_assets(t_global *global, int fd)
{
	char	*line;
	char	**split_line;
	int		i;

	i = 4;
	while (i)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (must_skip_line(line) == 1)
			continue ;
		split_line = ft_split(line, ' ');
		free(line);
		if (copy_assets(global, split_line) == 1)
			return (free_tab(split_line), free_gnl(fd), 1);
		free_tab(split_line);
		i--;
	}
	return (check_assets(global, fd));
}

/*
 * parse_map_color a function for get the RGB value of map color
 *
 * return status error or succes
 * */
int	parse_map_color(t_global *global, int fd)
{
	char	*line;
	char	**split_line;
	char	**split_color;
	int		i;

	i = 2;
	while (i)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (must_skip_line(line) == 1)
			continue ;
		split_line = ft_split(line, ' ');
		free(line);
		split_color = ft_split(split_line[1], ',');
		if (copy_color(global, split_color, split_line[0]) == 1)
			return (free_gnl(fd), free_tab(split_line),
				free_tab(split_color), 1);
		free_tab(split_line);
		free_tab(split_color);
		i--;
	}
	return (0);
}

/*
 * parse_map_matrice this function is use for make the matrice of the map
 *
 * return status error or succes
 * */
int	parse_map_matrice(t_global *global, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (must_skip_line(line) == 1)
		{
			if (i == 0)
				continue ;
			else
				return (free_gnl(fd), 1);
		}
		if (copy_line_map(global, i, line) == 1)
			return (free(line), free_gnl(fd), 1);
		free(line);
		i++;
	}
	global->map[i][0] = -2;
	return (0);
}

/*
 * parser function for parse the map.cub
 *
 * return status error or succes
 * */
int	parser(t_global *global, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("Error open file"));
	if (parse_map_assets(global, fd) == 0)
		if (parse_map_color(global, fd) == 0)
			if (parse_map_matrice(global, fd) == 0)
				return (printf("Parsing correct !\n"), close(fd), 0);
	return (error_mess("Parsing incorrect !"), close(fd), 1);
}
