#include "../inc/cub3d.h"

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
        main_data->player = 0;

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

