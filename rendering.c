/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:31:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/16 14:50:04 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_sl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	**split_map(char *map_name, int y)
{
	int		fd;
	char	**map_lines;
	char	*line;
	int		i;

	fd = open(map_name, O_RDONLY);
	map_lines = (char **)malloc(sizeof(char *) * (y + 1));
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_lines[i] = line;
		i++;
	}
	map_lines[i] = NULL;
	close(fd);
	return (map_lines);
}

char	**map_array(t_mlx *vars, char *map_name)
{
	int		y;
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	vars->map.y = y;
	close(fd);
	return (split_map(map_name, y));
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
			}
			else if (vars->map.map_lines[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					vars->sprites[E].image, x * 42, y * 42);
			x++;
		}
		y++;
	}
}
