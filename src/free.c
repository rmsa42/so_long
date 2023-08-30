/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:08:30 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/30 15:24:53 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_mlx *game)
{
	int	i;

	i = 0;
	while (i < 5)
		mlx_destroy_image(game->mlx_ptr, game->sprites[i++].image);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	i = 0;
	while (game->map.map_lines[i])
		free(game->map.map_lines[i++]);
	free(game->map.map_lines);
	free(game->mlx_ptr);
	exit(0);
}

void	error(t_mlx *game)
{
	int	i;

	i = 0;
	mlx_destroy_display(game->mlx_ptr);
	while (game->map.map_lines[i])
		free(game->map.map_lines[i++]);
	free(game->map.map_lines);
	free(game->mlx_ptr);
	exit(1);
}
