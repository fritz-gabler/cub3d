/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:22 by fgabler           #+#    #+#             */
/*   Updated: 2024/01/31 14:31:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_parsing	parser;

	get_input(&parser, ac, av);
	pars_input(&parser);
	file_parsing(&parser);
	get_file_content(&parser);
	valide_map_check(&parser);
	return (0);
}
