#include "cub3d.h"

void	replace_newline_with_null_terminator(char *string)
{
	if (string == NULL)
		return ;
	while (*string != '\n')
		string++;
	*string = '\0';
}
