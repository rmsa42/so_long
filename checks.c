/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:39:31 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/08 17:15:45 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
