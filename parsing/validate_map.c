#include "../inc/cub3d.h"

static bool	surroundings(int i, int j, char **map_lines, int invalid, t_main_data *main_data)
{
    // if ((i == 0 || j == 0) && map_lines[i][j] == '0')
    //     return (false);
    if (j > 0 && map_lines[i][j - 1] == invalid)
        return false;
    if (j < main_data->map_width - 1 && map_lines[i][j + 1] == invalid)
        return false;
    if (i > 0 && map_lines[i - 1][j] == invalid)
        return false;
    if (i < main_data->map_height - 1 && map_lines[i + 1][j] == invalid)
        return false;
    return true;
}

static bool check_void(char **map_lines, t_main_data *main_data)
{
	int		i;
    int     j;
	char	invalid;

	i = - 1;
    printf("\n\n");
    (void)map_lines;
	while (main_data->maplines[++i])
	{
		j = -1;
        printf("map line in check void: $%s$\n", main_data->maplines[i]);
		while (main_data->maplines[i][++j])
		{
			if (main_data->maplines[i][j] == ' ')
				invalid = '0';
			// else if (main_data->maplines[i][j] == main_data.)
			// 	invalid = ' ';
			else
				continue ;
			if (!surroundings(i, j, main_data->maplines, invalid, main_data))
            {
                printf("\n\n\nEMPPPPTYYYYY SPACES WITHIN THE MAPPPPPPPPP!!!!!!!!!!!!!!!!!\n");
                return (false);
            }
		}
	}
    return (true);
}

bool validate_map(char **map_lines, int j, t_main_data *main_data)
{
    (void)j;
    if (!check_void(map_lines, main_data))
        return (false);
    return (true);
}