/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/10 17:03:13 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
# define R 20

void	render_line(t_image *player);

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	t_image	image;
	t_line	line;

	image = (t_image){};
	line = (t_line){};
	image.line = &line;
	image.angle = 0;
	int x = -1;
	int	y = -1;
	int	map[10][13] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 2, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};

	image.mlx = mlx_init(50 * 13, 50 * 10, "minimap", true);
	image.window_lin = mlx_new_image(image.mlx, 50 * 13, 50 * 10);
	image.background = mlx_new_image(image.mlx, 50 * 13, 50 * 10);
	mlx_image_to_window(image.mlx, image.window_lin, 0, 0);
	mlx_image_to_window(image.mlx, image.background, x, y);
	mlx_key_hook(image.mlx, handle_keyhook, &image);
	render_map(&image, map);
	mlx_loop(image.mlx);
	mlx_terminate(image.mlx);
	return (0);
}
