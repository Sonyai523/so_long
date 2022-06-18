/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhozkan <muhozkan@student.42.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:04:11 by muhozkan          #+#    #+#             */
/*   Updated: 2022/04/26 01:04:11 by muhozkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	*put_image(t_image image, int x, int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx,
			image.relative_path, &image.img_width, &image.img_height);
	mlx_put_image_to_window(image.wlx.mlx, image.wlx.window, image.img, x, y);
	return (image.img);
}

t_block	set_block(char name)
{
	t_block	maps[7];
	int		i;

	maps[0] = (t_block){"1", "./img/wall50.xpm"};
	maps[1] = (t_block){"0", "./img/back50.xpm"};
	maps[2] = (t_block){"C", "./img/fly50.xpm"};
	maps[3] = (t_block){"P", "./img/jaba50.xpm"};
	maps[4] = (t_block){"E", "./img/exit50.xpm"};
	maps[5] = (t_block){"N", "./img/snake50.xpm"};
	maps[6] = (t_block){NULL, NULL};
	i = 0;
	while (maps[i].name != NULL)
	{
		if (maps[i].name[0] == name)
		{
			return (maps[i]);
			break ;
		}
		i++;
	}
	return (maps[6]);
}

void	move_4(t_game *game, int x, int y)
{
	int		i;
	int		j;
	t_image	image;

	image.wlx = *game;
	image.relative_path = "./img/snake50.xpm";
	while (game->map[y][x + 1] != '1')
	{
		update2(game, (x * 50), y * 50);
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'N';
		i = y * 50;
		j = (x * 50) + 50;
		put_image(image, j, i);
		x++;
	}	
}
