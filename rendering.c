/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:31:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/31 16:59:28 by rumachad         ###   ########.fr       */
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

void	*put_sprite(t_mlx *vars, char *img_name, int k, int i)
{
	t_sprite	sprite;
	
	sprite.image = mlx_xpm_file_to_image(vars->mlx_ptr, img_name, &sprite.x, &sprite.y);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, sprite.image, k * 42, i * 42);
	return (sprite.image);
}

void	put_map(t_mlx *vars, t_map map, t_player *player, char *map_name)
{
	int	i;
	int	k;
	int	fd;
	char	*line;
	
	fd = open(map_name, O_RDONLY);
	i = 0;
	while (i < map.y)
	{
		k = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (k < map.x)
		{
			if (line[k] == '1')
				put_sprite(vars, "sprites/wall.xpm", k, i);
			if (line[k] == '0')
				put_sprite(vars, "sprites/path.xpm", k, i);
			if (line[k] == 'P')
			{
				player->player_image = put_sprite(vars, "sprites/player.xpm", k, i);
				player->x = (i * map.x) + k;
				player->y = i;
			}
			k++;
		}
		i++;
	}
	close(fd);
}
