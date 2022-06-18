/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhozkan <muhozkan@student.42.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 01:04:31 by muhozkan          #+#    #+#             */
/*   Updated: 2022/04/26 01:04:31 by muhozkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	moves(t_game *game, char *str)
{
	t_image	image;

	image.relative_path = "./img/wall50.xpm";
	image.wlx = *game;
	put_image(image, 17 * 50, 0);
	put_image(image, 17 * 50 + 50, 0);
	mlx_string_put(image.wlx.mlx, image.wlx.window,
		17 * 50, 20, 0x00FF66, "MOVES:");
	mlx_string_put(image.wlx.mlx, image.wlx.window,
		17 * 50 + 50, 20, 0x00FF66, str);
	free(str);
}

void	right(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	char	*str;

	image.relative_path = "./img/jaba50.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x + 50;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		str = ft_itoa(game->player.hareket);
		moves(game, str);
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
	char	*str;

	image.relative_path = "./img/jaba50.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x - 50;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		str = ft_itoa(game->player.hareket);
		moves(game, str);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	up(t_game *game)
{
	int		i;
	int		j;
	t_image	image;
	char	*str;

	image.relative_path = "./img/jaba50.xpm";
	image.wlx = *game;
	i = game->player.y - 50;
	j = game->player.x;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		str = ft_itoa(game->player.hareket);
		moves(game, str);
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
	char	*str;

	image.relative_path = "./img/jaba50.xpm";
	image.wlx = *game;
	i = game->player.y + 50;
	j = game->player.x;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		str = ft_itoa(game->player.hareket);
		moves(game, str);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}
