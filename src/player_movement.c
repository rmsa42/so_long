/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 03:27:08 by rui               #+#    #+#             */
/*   Updated: 2023/08/30 14:05:47 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(t_mlx *game, int next_x, int next_y, int coin)
{
	void		*sprite_ptr;
	static int	flag;

	sprite_ptr = game->sprites[0].image;
	if (game->map.map_lines[next_y][next_x] == '1')
		return (False);
	if (flag == 1)
	{
		sprite_ptr = game->sprites[E].image;
		flag = 0;
	}
	if ((game->map.map_lines[next_y][next_x] == 'E'
		&& coin != game->sprites[C].coin_count))
		flag = 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite_ptr,
		game->sprites[P].curr_x * 42, game->sprites[P].curr_y * 42);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->sprites[P].image, next_x * 42, next_y * 42);
	game->sprites[P].curr_x = next_x;
	game->sprites[P].curr_y = next_y;
	return (True);
}

void	check_key(int key, t_mlx *game, int coin)
{
	static int	moves;
	int			check_move;
	int			next_y;
	int			next_x;

	check_move = 0;
	next_x = game->sprites[P].curr_x;
	next_y = game->sprites[P].curr_y;
	if (key == S)
		check_move = player_move(game, next_x, next_y + 1, coin);
	else if (key == A)
		check_move = player_move(game, next_x - 1, next_y, coin);
	else if (key == D)
		check_move = player_move(game, next_x + 1, next_y, coin);
	else if (key == W)
		check_move = player_move(game, next_x, next_y - 1, coin);
	if (check_move != 0)
		ft_printf("Moves:%d\n", ++moves);
}

int	key_press(int key, t_mlx *game)
{
	static int	coin;

	if (key == Esc)
		close_game(game);
	else if (key == S || key == A || key == D || key == W)
		check_key(key, game, coin);
	if (game->map.map_lines[game->sprites[P].curr_y]
		[game->sprites[P].curr_x] == 'E'
		&& coin == game->sprites[C].coin_count)
		close_game(game);
	if (game->map.map_lines[game->sprites[P].curr_y]
		[game->sprites[P].curr_x] == 'C')
	{
		game->map.map_lines[game->sprites[P].curr_y]
		[game->sprites[P].curr_x] = '0';
		coin++;
	}
	return (0);
}
