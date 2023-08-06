/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:02:23 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/06 15:05:32 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"

typedef struct s_sprite
{
	int x;
	int y;
	void *image;
}				t_sprite;

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	t_sprite	sprites[5];
}				t_mlx;

typedef struct s_map
{
	int	x;
	int	y;
}				t_map;


t_map	read_map(char *map_name);
void	put_map(t_mlx *vars, t_map map, char *map_name);
void	*put_sprite(t_mlx *vars, char *img_name, int x, int y);

#endif