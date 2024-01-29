#include "cub3d.h"

void	map_border_check(t_parsing *parser)
{
	if (parser->error_occurred == true)
		return ;
	int		number_zeros_before;
	int		number_zeros_after;
	char	**copied_map;

	count_zeros_in_map(&number_zeros_before, parser);
	copy_map_with_two_extra_lines(&copied_map, parser);
	add_line_of_spaces_at_top_and_bottom(copied_map, parser);
	fill_map_with_aligned_lines(copied_map, parser);
	/*
	int	i;
	int	rows;
	i = 0;
	get_number_of_map_rows(parser, &rows);
	rows += 2;
	while(i < rows)
	{
		if (i > 10)
			printf("%d [%s]\n", i, copied_map[i]);
		if (i < 10)
			printf("%d  [%s]\n", i, copied_map[i]);
		i++;
	}
	*/
	(void) number_zeros_after;
	/*
	double_array_len = count_doupple_arry_quantity(parser->map);
	printf("array quantity %d\n", double_array_len);
	printf("str len %zu\n", ft_strlen(parser->map[4]));
	tmp_map = ft_strjoin("5", parser->map[4]);
	tmp_map = ft_strjoin(tmp_map, "5");
	printf("%s\n", tmp_map);
	printf("str len %zu\n", ft_strlen(tmp_map));
	*/
}
