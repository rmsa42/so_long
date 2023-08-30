/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:53:22 by rui               #+#    #+#             */
/*   Updated: 2023/08/30 12:25:15 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_pce(t_mlx *game, int *count, int x, int y)
{
	if (game->map.map_lines[y][x] == 'P')
	{
		*count = *count + 1;
		game->sprites[P].curr_x = x;
		game->sprites[P].curr_y = y;
	}
	else if (game->map.map_lines[y][x] == 'C')
		game->sprites[C].coin_count++;
	else if (game->map.map_lines[y][x] == 'E')
		*count = *count + 1;
	else if (game->map.map_lines[y][x] != '1'
		&& game->map.map_lines[y][x] != '0'
		&& game->map.map_lines[y][x] != '\n')
	{
		ft_printf("Error\nInvalid Map components\n");
		error(game);
	}
}

void	check_map_pce(t_mlx *game)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (game->map.map_lines[y])
	{
		x = 0;
		while (game->map.map_lines[y][x])
		{
			if_pce(game, &count, x, y);
			x++;
		}
		y++;
	}
	if (count != 2 || game->sprites[C].coin_count < 1)
	{
		ft_printf("Error\nInvalid Map components\n");
		error(game);
	}
}
