/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:31:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/14 16:38:52 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_sl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	read_map(t_mlx *vars, char *map_name)
{
	int		fd;
	int		check_x;
	char	*line;

	vars->map.x = 0;
	vars->map.y = 0;
	fd = open(map_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		vars->map.x = ft_strlen_sl(line) - 1;
		if (vars->map.y == 0)
			check_x = vars->map.x;
		if (check_x != vars->map.x)
		{
			mlx_destroy_display(vars->mlx_ptr);
			free(vars->mlx_ptr);
			exit(1);
		}
		vars->map.y++;
		free(line);
	}
	close(fd);
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
	vars->sprites[0].image = mlx_xpm_file_to_image(vars->mlx_ptr, "sprites/path.xpm", \
							&vars->sprites[0].curr_x, &vars->sprites[0].curr_y);
	vars->sprites[1].image = mlx_xpm_file_to_image(vars->mlx_ptr, "sprites/wall.xpm", \
							&vars->sprites[1].curr_x, &vars->sprites[1].curr_y);
	vars->sprites[2].image = mlx_xpm_file_to_image(vars->mlx_ptr, "sprites/player.xpm", \
							&vars->sprites[2].curr_x, &vars->sprites[2].curr_y);
	vars->sprites[3].image = mlx_xpm_file_to_image(vars->mlx_ptr, "sprites/coin.xpm", \
							&vars->sprites[3].curr_x, &vars->sprites[3].curr_y);
	vars->sprites[4].image = mlx_xpm_file_to_image(vars->mlx_ptr, "sprites/exit.xpm", \
							&vars->sprites[4].curr_x, &vars->sprites[4].curr_y);
}


void	put_map(t_mlx *vars)
{
	int	y;
	int	x;
	
	y = 0;
	while (vars->map.map_lines[y])
	{
		x = 0;
		while (vars->map.map_lines[y][x])
		{
			if (vars->map.map_lines[y][x] == '0')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[0].image, x * 42, y * 42);
			else if (vars->map.map_lines[y][x] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[1].image, x * 42, y * 42);
			else if (vars->map.map_lines[y][x] == 'P')
			{
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[P].image, x * 42, y * 42);
				vars->sprites[P].curr_x = x;
				vars->sprites[P].curr_y = y;
			}
			else if (vars->map.map_lines[y][x] == 'C')
			{
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[C].image, x * 42, y * 42);
				vars->sprites[C].coin_count++;
			}
			else if (vars->map.map_lines[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[E].image, x * 42, y * 42);
			x++;
		}
		y++;
	}
}
