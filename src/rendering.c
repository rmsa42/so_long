/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:31:47 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/04 11:53:53 by rumachad         ###   ########.fr       */
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

	if (!ft_strnstr(map_name, ".ber", ft_strlen(map_name)))
		return (NULL);
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
