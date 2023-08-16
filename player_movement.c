/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 03:27:08 by rui               #+#    #+#             */
/*   Updated: 2023/08/16 15:35:22 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(t_mlx *vars, int next_x, int next_y, int coin)
{
	void		*sprite_ptr;
	static int	flag;

	sprite_ptr = vars->sprites[0].image;
	if (vars->map.map_lines[next_y][next_x] == '1')
		return (False);
	if (flag == 1)
	{
		sprite_ptr = vars->sprites[E].image;
		flag = 0;
	}
	if ((vars->map.map_lines[next_y][next_x] == 'E'
		&& coin != vars->sprites[C].coin_count))
		flag = 1;
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, sprite_ptr,
		vars->sprites[P].curr_x * 42, vars->sprites[P].curr_y * 42);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->sprites[P].image, next_x * 42, next_y * 42);
	vars->sprites[P].curr_x = next_x;
	vars->sprites[P].curr_y = next_y;
	return (True);
}

void	check_key(int key, t_mlx *vars, int coin)
{
	static int	moves;
	int			mmove;
	int			next_y;
	int			next_x;

	mmove = 0;
	next_x = vars->sprites[P].curr_x;
	next_y = vars->sprites[P].curr_y;
	if (key == S)
		mmove = player_move(vars, next_x, next_y + 1, coin);
	else if (key == A)
		mmove = player_move(vars, next_x - 1, next_y, coin);
	else if (key == D)
		mmove = player_move(vars, next_x + 1, next_y, coin);
	else if (key == W)
		mmove = player_move(vars, next_x, next_y - 1, coin);
	if (mmove != 0)
		ft_printf("Moves:%d\n", ++moves);
}

int	key_press(int key, t_mlx *vars)
{
	static int	coin;

	if (key == Esc)
		close_game(vars);
	else if (key == S || key == A || key == D || key == W)
		check_key(key, vars, coin);
	if (vars->map.map_lines[vars->sprites[P].curr_y]
		[vars->sprites[P].curr_x] == 'E'
		&& coin == vars->sprites[C].coin_count)
		close_game(vars);
	if (vars->map.map_lines[vars->sprites[P].curr_y]
		[vars->sprites[P].curr_x] == 'C')
	{
		vars->map.map_lines[vars->sprites[P].curr_y]
		[vars->sprites[P].curr_x] = '0';
		coin++;
	}
	return (0);
}
