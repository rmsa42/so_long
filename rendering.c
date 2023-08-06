/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:31:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/06 15:28:40 by rui              ###   ########.fr       */
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
		while (line[i] && map.y == 0)
		{
			if (line[i] == '1')
				map.x = map.x + 1;
			i++;
		}
		map.y = map.y + 1;
		free(line);
	}
	close(fd);
	return (map);
}

void	*put_sprite(t_mlx *vars, char *img_name, int x, int y)
{
	t_sprite	sprite;
	
	sprite.image = mlx_xpm_file_to_image(vars->mlx_ptr, img_name, &sprite.x, &sprite.y);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, sprite.image, x * 42, y * 42);
	return (sprite.image);
}

void	put_map(t_mlx *vars, t_map map, char *map_name)
{
	int	y;
	int	x;
	int	fd;
	char	*line;
	
	fd = open(map_name, O_RDONLY);
	y = 0;
	while (y < map.y)
	{
		x = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (x < map.x)
		{
			if (line[x] == '1')
				vars->sprites[0].image = put_sprite(vars, "sprites/wall.xpm", x, y);
			else if (line[x] == '0')
				vars->sprites[1].image = put_sprite(vars, "sprites/path.xpm", x, y);
			else if (line[x] == 'P')
			{
				vars->sprites[2].image = put_sprite(vars, "sprites/player.xpm", x, y);
				vars->sprites[2].x = x;
				vars->sprites[2].y = y;
			}
			else if (line[x] == 'C')
			{
				vars->sprites[3].image = put_sprite(vars, "sprites/coin.xpm", x, y);
				vars->sprites[3].x = x;
				vars->sprites[3].y = y;
			}
			else if (line[x] == 'E')
			{
				vars->sprites[4].image = put_sprite(vars, "sprites/exit.xpm", x, y);
				vars->sprites[4].x = x;
				vars->sprites[4].y = y;
			}
			x++;
		}
		y++;
	}
	close(fd);
}
