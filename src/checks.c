/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:39:31 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/29 15:04:39 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_flood_fill(t_mlx *game, int x, int y, char **cpy_map)
{
	static int	count;

	if (cpy_map[y][x] == '1' || x >= game->map.x || y >= game->map.y
		|| x <= 0 || y <= 0)
		return (False);
	else
	{
		if (cpy_map[y][x] == 'C' || cpy_map[y][x] == 'E')
			count++;
		cpy_map[y][x] = '1';
		my_flood_fill(game, x + 1, y, cpy_map);
		my_flood_fill(game, x - 1, y, cpy_map);
		my_flood_fill(game, x, y + 1, cpy_map);
		my_flood_fill(game, x, y - 1, cpy_map);
	}
	return (count);
}

void	check_map_f(t_mlx *game)
{
	char	**cpy_map;
	int		f;
	int		y;

	y = 0;
	f = 0;
	cpy_map = (char **)calloc(sizeof(char *), (game->map.y + 1));
	while (y < game->map.y)
	{
		cpy_map[y] = ft_strdup(game->map.map_lines[y]);
		y++;
	}
	f = my_flood_fill(game, game->sprites[P].curr_x,
			game->sprites[P].curr_y, cpy_map);
	y = 0;
	while (cpy_map[y])
	{
		free(cpy_map[y]);
		y++;
	}
	free(cpy_map);
	if (f != game->sprites[C].coin_count + 1)
		error(game);
}

void	check_map_wall(t_mlx *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.x)
	{
		if (game->map.map_lines[0][x] != '1'
		|| game->map.map_lines[game->map.y - 1][x] != '1')
			error(game);
		x++;
	}
	y = 0;
	while (y < game->map.y)
	{
		if (game->map.map_lines[y][0] != '1'
		|| game->map.map_lines[y][game->map.x - 1] != '1')
			error(game);
		y++;
	}
}

void	check_map(t_mlx *game)
{
	int		check_x;
	int		y;

	y = 0;
	check_x = ft_strlen_sl(game->map.map_lines[0]);
	while (game->map.map_lines[y])
	{
		if (check_x != ft_strlen_sl(game->map.map_lines[y]))
			error(game);
		y++;
	}
	game->map.x = check_x;
	check_map_wall(game);
	check_map_pce(game);
	check_map_f(game);
}
