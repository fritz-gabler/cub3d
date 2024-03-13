/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/13 22:27:50 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_math_struct(t_cub3d *cub3d)
{
	static t_line		line;
	static t_player		player;
	static t_raycaster	raycaster;
	static t_minimap	hud;

	line = (t_line){};
	player = (t_player){};
	raycaster = (t_raycaster){};
	hud = (t_minimap){};
	cub3d->line = &line;
	cub3d->player = &player;
	cub3d->raycaster = &raycaster;
	cub3d->hud = &hud;
}

int	main(int ac, char **av)
{
	t_cub3d		cub3d;
	t_parsing	parser;
	t_game		game;

	cub3d = (t_cub3d){};
	init_math_struct(&cub3d);
	set_up_parser_struct(&parser, ac, av);
	make_structs_accessible(&game, &parser);
	parse_input(&parser);
	file_parsing(&parser);
	get_file_content(&parser);
	valide_map_check(&parser);
	set_up_game_struct(&parser, &game);
	if (parser.error_occurred == false)
	{
		cub3d.meta_data = &game;
		if (launch_game(&cub3d) == EXIT_FAILURE)
			free_execution(&cub3d, EXIT_FAILURE);
	}

	system("killall afplay");
	free_structs(&game, &parser);
	return (0);
}
