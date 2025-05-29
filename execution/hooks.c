#include "cub3d.h"

int	quit_win(t_main_data *main_data)
{
	exit_program("closed", NULL); //check for memory leaks
	return (0);
}

static int	key_press_handler(int key, t_main_data *main_data)
{
	if (key == ESC)
		quit_win(main_data);
	if (key == KEY_LA)
		main_data->player.rotate -= 1;
	if (key == KEY_RA)
		main_data->player.rotate += 1;
	if (key == W)
		main_data->player.move_y = 1;
	if (key == A)
		main_data->player.move_x = -1;
	if (key == S)
		main_data->player.move_y = -1;
	if (key == D)
		main_data->player.move_x = 1;
	return (0);
}

//resets everything
static int	key_release_handler(int key,t_main_data *main_data)
{
	if (key == ESC)
		quit_win(main_data);
	if (key == W && main_data->player.move_y == 1)
		main_data->player.move_y = 0;
	if (key == S && main_data->player.move_y == -1)
		main_data->player.move_y = 0;
	if (key == A && main_data->player.move_x == -1)
		main_data->player.move_x += 1;
	if (key == D && main_data->player.move_x == 1)
		main_data->player.move_x -= 1;
	if (key == KEY_LA && main_data->player.rotate <= 1)
		main_data->player.rotate = 0;
	if (key == KEY_RA && main_data->player.rotate >= -1)
		main_data->player.rotate = 0;
	return (0);
}

int	render(t_main_data *data)
{
	main_data->player.has_moved += move_player(main_data);
	if (main_data->player.has_moved == 0)
		return (0);
	render_images(data); // check what name should be changed
	return (0);
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->wall_height = 0;
	ray->drw_start = 0;
	ray->drw_end = 0;
}


