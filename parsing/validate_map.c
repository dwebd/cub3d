#include "../inc/cub3d.h"
bool get_angle(t_main_data *main_data, char **maplines, int height)
{
		int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (maplines[i][j])
		{
			if (ft_strchr("NEWS", maplines[i][j]))
			{
				if (maplines[i][j] == 'N')
					main_data->direction = (3 * M_PI) / 2;
				else if (maplines[i][j] == 'E')
					main_data->direction = 0;
				else if (maplines[i][j] == 'W')
					main_data->direction = M_PI;
				else if (maplines[i][j] == 'S')
					main_data->direction = M_PI / 2;
			}
			j++;
		}
		i++;
	}
	return(true);
}

bool find_player(t_main_data *main_data)
{
	int	i;
	int j;

	i = -1;
	while (main_data->maplines[++i])
	{
		j = -1;
		while (main_data->maplines[i][++j])
		{
			if (ft_strchr("NEWS", main_data->maplines[i][j]))
			{
				printf("after searching news: %c\n", main_data->maplines[i][j]);
				if (!main_data->player)
				{
					main_data->player_y = i + 0.5;
					main_data->player_x = j + 0.5;
					main_data->player = main_data->maplines[i][j];
					main_data->maplines[i][j] = '0';
				}
				else
					{
                        printf("extra player\n");
                        return (false);
                    }
			}
		}
	}
	if (!main_data->player)
	{
        printf("no player\n");
        return (false);
    }
    return (true);
}

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

static bool check_void(t_main_data *main_data)
{
	int		i;
    int     j;
	char	invalid;

	i = - 1;
    printf("\n\n");
	while (main_data->maplines[++i])
	{
		j = -1;
        printf("map line in check void: $%s$\n", main_data->maplines[i]);
		while (main_data->maplines[i][++j])
		{
			if (main_data->maplines[i][j] == ' ')
				invalid = '0';
			// else if (main_data->maplines[i][j] == main_data)
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

bool validate_map(t_main_data *main_data)
{
	if(!find_player(main_data))
        return(false);
    if (!check_void(main_data))
        return (false);
	if(!get_angle(main_data, main_data->maplines, main_data->map_height))
		return (false);
    return (true);
}