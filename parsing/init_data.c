#include "../inc/cub3d.h"
void	init_player(t_player *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

bool init_main_data(t_main_data *main_data)
{
    int i = 0;

    //init textures
    while (i < 4)
    {
        main_data->textures[i].path = NULL;
        main_data->textures[i].type = i; // 0 - NO, 1 - SO, 2 - WE, 3 - EA

        main_data->floor.red = -1;
        main_data->floor.green = -1;
        main_data->floor.blue = -1;
        main_data->floor.is_set = false;
        main_data->ceiling.is_set = false;
        main_data->ceiling.red = -1;
        main_data->ceiling.green = -1;
        main_data->ceiling.blue = -1;
        init_player(&main_data->player);
        main_data->direction = 0;
        main_data->player_x = -1;
        main_data->player_y = -1;

        i++;
    }
    return (true);
}

    // Проверка после инициализации
    // i = 0;
    // while (i < 4)
    // {
    //     printf("Texture %d: type = %d, path = %s\n",
    //             i,
    //             data->textures[i].type,
    //             data->textures[i].path);
    //     i++;
    // }

    static void	init_player_n_s(t_player *player)
{
	if (player->dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else
		return ;
}

static void	init_player_e_w(t_player *player)
{
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else
		return ;
}
    void	init_dir_player(t_main_data *main_data)
    {
        init_player_n_s(&main_data->player);
        init_player_e_w(&main_data->player);
    }
