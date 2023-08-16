/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:39:31 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/16 15:30:12 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_wall(t_mlx *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < vars->map.x)
	{
		if (vars->map.map_lines[0][x] != '1'
		|| vars->map.map_lines[vars->map.y - 1][x] != '1')
			error(vars);
		x++;
	}
	y = 0;
	while (y < vars->map.y)
	{
		if (vars->map.map_lines[y][0] != '1'
		|| vars->map.map_lines[y][vars->map.x - 1] != '1')
			error(vars);
		y++;
	}
}

void	check_map_pce(t_mlx *vars)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (vars->map.map_lines[y])
	{
		x = 0;
		while (vars->map.map_lines[y][x])
		{
			if (vars->map.map_lines[y][x] == 'P')
				count++;
			else if (vars->map.map_lines[y][x] == 'C')
				vars->sprites[C].coin_count++;
			else if (vars->map.map_lines[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count != 2 || vars->sprites[C].coin_count < 1)
		error(vars);
}

void	check_map(t_mlx *vars)
{
	int	check_x;
	int	y;

	y = 0;
	check_x = ft_strlen_sl(vars->map.map_lines[0]);
	while (vars->map.map_lines[y])
	{
		if (check_x != ft_strlen_sl(vars->map.map_lines[y]))
			error(vars);
		y++;
	}
	vars->map.x = check_x;
	check_map_wall(vars);
	check_map_pce(vars);
}

int	check_wall_x(t_mlx *vars, int curr_y, int next_x)
{
	if (vars->map.map_lines[curr_y][next_x] == '1')
		return (1);
	else
		return (0);
}

int	check_wall_y(t_mlx *vars, int curr_x, int next_y)
{
	if (vars->map.map_lines[next_y][curr_x] == '1')
		return (1);
	else
		return (0);
}
