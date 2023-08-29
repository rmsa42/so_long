/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:31:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/29 18:55:28 by rui              ###   ########.fr       */
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
	if (map_lines == NULL)
		return (NULL);
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

char	**map_array(t_mlx *game, char *map_name)
{
	int		y;
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	y = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	game->map.y = y;
	close(fd);
	return (split_map(map_name, y));
}

void	init_sprites(t_mlx *game)
{
	game->sprites[0].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/path.xpm",
			&game->sprites[0].curr_x, &game->sprites[0].curr_y);
	game->sprites[1].image = mlx_xpm_file_to_image(game->mlx_ptr, 
			"sprites/wall.xpm",
			&game->sprites[1].curr_x, &game->sprites[1].curr_y);
	game->sprites[P].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/player.xpm",
			&game->sprites[P].curr_x, &game->sprites[P].curr_y);
	game->sprites[C].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/coin.xpm",
			&game->sprites[C].curr_x, &game->sprites[C].curr_y);
	game->sprites[E].image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/exit.xpm",
			&game->sprites[E].curr_x, &game->sprites[E].curr_y);
}
