/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhozkan <muhozkan@student.42.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:03:25 by muhozkan          #+#    #+#             */
/*   Updated: 2022/04/26 01:03:25 by muhozkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_game *game, int x, int y)
{
	t_image	image;

	image.relative_path = "./img/back50.xpm";
	image.wlx = *game;
	put_image(image, game->player.x, game->player.y);
	put_image(image, x, y);
}

void	right(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/jaba50.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x + 50;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"Number of movements = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	left(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/jaba50.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x - 50;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"Number of movements = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.x = j;
		game->player.y = i;
		put_image(image, j, i);
	}
}

void	up(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/jaba50.xpm";
	image.wlx = *game;
	j = game->player.x;
	i = game->player.y - 50;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"Number of movements = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	down(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/jaba50.xpm";
	image.wlx = *game;
	i = game->player.y + 50;
	j = game->player.x;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"Number of movements = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}
