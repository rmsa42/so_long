/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:31:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/08 15:40:11 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	read_map(char *map_name)
{
	t_map	map;
	int		i;
	int		fd;
	char	*line;

	map.x = 0;
	map.y = 0;
	i = 0;
	fd = open(map_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[i] != '\n' && map.y == 0)
		{
			map.x = map.x + 1;
			i++;
		}
		map.y = map.y + 1;
		free(line);
	}
	close(fd);
	return (map);
}

char	**split_map(t_map map, char *map_name)
{
	int	fd;
	int	i;
	char **map_lines;
	
	i = 0;
	fd = open(map_name, O_RDONLY);
	map_lines = (char **)malloc(sizeof(char *) * (map.y + 1));
	while (i < map.y)
	{
		map_lines[i] = (char *)malloc(sizeof(char) * (map.x + 1));
		read(fd, map_lines[i], map.x + 1);
		map_lines[i][map.x] = '\0';
		i++;
	}
	map_lines[i] = NULL;
	return (map_lines);
}

void	init_sprites(t_mlx *vars)
{
	vars->sprites[0].image = mlx_xpm_file_to_image(vars->mlx_ptr, "sprites/wall.xpm", \
									&vars->sprites[0].x, &vars->sprites[0].y);
	vars->sprites[1].image = mlx_xpm_file_to_image(vars->mlx_ptr, "sprites/path.xpm", \
									&vars->sprites[1].x, &vars->sprites[1].y);
	vars->sprites[2].image = mlx_xpm_file_to_image(vars->mlx_ptr, "sprites/player.xpm", \
									&vars->sprites[2].x, &vars->sprites[2].y);
	vars->sprites[3].image = mlx_xpm_file_to_image(vars->mlx_ptr, "sprites/coin.xpm", \
									&vars->sprites[3].x, &vars->sprites[3].y);
	vars->sprites[4].image = mlx_xpm_file_to_image(vars->mlx_ptr, "sprites/exit.xpm", \
									&vars->sprites[4].x, &vars->sprites[4].y);
}


void	put_map(t_mlx *vars)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < vars->map.y)
	{
		x = 0;
		while (x < vars->map.x)
		{
			if (vars->map.map_lines[y][x] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[0].image, x * 42, y * 42);
			else if (vars->map.map_lines[y][x] == '0')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[1].image, x * 42, y * 42);
			else if (vars->map.map_lines[y][x] == 'P')
			{
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[2].image, x * 42, y * 42);
				vars->sprites[2].x = x;
				vars->sprites[2].y = y;
			}
			else if (vars->map.map_lines[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[3].image, x * 42, y * 42);
			else if (vars->map.map_lines[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[4].image, x * 42, y * 42);
			x++;
		}
		y++;
	}
}
