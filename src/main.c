#include "../inc/cub3d.h"

int main(int ac, char **av)
{
    t_main_data main_data;
    char **file_content;

    file_content = NULL;
    if(ac != 2)
        exit_program("Error: need the path for map file", NULL);
    // printf(">>> Stage 1: checking file format\n");
    if(!check_file_format(av[1]))
        exit_program("Error: wrong format file: .cub\n", NULL);
    // printf(">>> Stage 2: checking if file can be opened\n");
    if(!valid_file(av[1]))
        exit_program("Error: file   can not be opened\n", NULL);
    // printf(">>> Stage 3: parsing content\n");
    if(!parse_content(av[1], &file_content))
        exit_program("Error: invalid content\n", NULL);
    // printf(">>> Stage 4: validating content\n");
    if(!valid_content(file_content, &main_data))
         exit_program("Error: invalid content\n", NULL);
    init_dir_player(&main_data);
    mlx_initialize(&main_data);
    clean(file_content);
    return(1);
}

void mlx_initialize(t_main_data *main_data)
{
    main_data->mlx = mlx_init();
	if (!main_data->mlx)
		exit_program("Error: Mlx cannot be initialized", NULL); //check memory leaks
	main_data->win = mlx_new_window(main_data->mlx, WIN_W, WIN_H,"CUB3D");
	if (!main_data->win)
        exit_program("Error: window cannot be created", NULL); //check memory leaks
	main_data->img.image = mlx_new_image(main_data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!main_data->img.image)
        exit_program("Error: image cannot be created", NULL); //check memory leaks
	main_data->img.buff = mlx_get_data_addr(main_data->img.image,
			&main_data->img.bpp, &main_data->img.line_l, &main_data->img.endian);
    if (!load_textures(main_data))
        exit_program("Error: Failed to load textures", NULL); //check memory leaks

    //mlx_hook(main_data->win, ON_DESTROY, 0, quit_win, main_data);
	mlx_hook(main_data->win, KeyPress, KeyPressMask, key_press_handler, main_data);
    mlx_hook(main_data->win, KeyRelease, KeyReleaseMask, key_release_handler, main_data);

    // Set up window close event (optional but good for ESC or window X button)
    mlx_hook(main_data->win, 17, 0, close_window, main_data); // 17 is the "DestroyNotify" event

    // Set up the game loop to update frame by frame (for smooth movement)
    mlx_loop_hook(main_data->mlx, game_loop, main_data);
}