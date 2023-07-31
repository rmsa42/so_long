/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:02:23 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/31 17:00:08 by rumachad         ###   ########.fr       */
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
	t_sprite	im;
}				t_mlx;

typedef struct s_map
{
	int	x;
	int	y;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	void	*player_image;
}						t_player;

t_map	read_map(char *map_name);
void	put_map(t_mlx *vars, t_map map, t_player *player, char *map_name);

#endif