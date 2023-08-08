/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:23:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/08 17:32:26 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_x(t_mlx *vars, int curr_y, int curr_x, int next_x)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[1].image,
		curr_x * 42, curr_y * 42);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[2].image,
		next_x * 42, curr_y * 42);
	vars->sprites[2].x = next_x;
}

void	player_move_y(t_mlx *vars, int curr_y, int curr_x, int next_y)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[1].image,
		curr_x * 42, curr_y * 42);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->sprites[2].image,
		curr_x * 42, next_y * 42);
	vars->sprites[2].y = next_y;
}

void	check_key(int key, t_mlx *vars, int *moves)
{
	int y;
	int x;

	x = vars->sprites[2].x;
	y = vars->sprites[2].y;	
	if (key == S && check_wall_y(vars, x, y + 1) == 0)
		player_move_y(vars, y, x, y + 1);
	else if (key == A && check_wall_x(vars, y, x - 1) == 0)
		player_move_x(vars, y, x, x - 1);
	else if (key == D && check_wall_x(vars, y, x + 1) == 0)
		player_move_x(vars, y, x, x + 1);
	else if (key == W && check_wall_y(vars, x, y - 1) == 0)
		player_move_y(vars, y, x, y - 1);
	
}

int key_press(int key, t_mlx *vars)
{
	static int	coin;
	static int	moves;

	if (key == Esc)
		close_game(vars);
	else if (key == S || key == A || key == D || key == W)
	{
		check_key(key, vars, &moves);
	}
	if (vars->map.map_lines[vars->sprites[2].y][vars->sprites[2].x] == 'E' && coin == 1)
		close_game(vars);
	if (vars->map.map_lines[vars->sprites[2].y][vars->sprites[2].x] == 'C'
		&& coin != 1)
		coin++;
	printf("Coin:%d\n", coin);
	return (0);
}

int main(int argc, char *argv[])
{
	t_mlx	vars;

	if (argc == 2)
	{
		vars.mlx_ptr = mlx_init();
		vars.map = read_map(argv[1]);
		init_sprites(&vars);

		vars.map.map_lines = split_map(vars.map, argv[1]);

		vars.win_ptr = mlx_new_window(vars.mlx_ptr, vars.map.x * 42, vars.map.y * 42, "so_long");
		put_map(&vars); 
		mlx_hook(vars.win_ptr, 2, KeyPressMask, key_press, &vars);
		mlx_loop(vars.mlx_ptr);
	}
	return (0);
}
