#include "cub3d.h"

static int	move_player_fb(t_main_data *main_data, int direction)
{
	double	upd_x;
	double	upd_y;

	upd_x = main_data->player.pos_x + main_data->player.dir_x * SPEED * direction;
	upd_y = main_data->player.pos_y + main_data->player.dir_y * SPEED * direction;
	return (validate_move(main_data, upd_x, upd_y));
}

static int	move_player_lr(t_main_data *main_data, int direction)
{
	double	upd_x;
	double	upd_y;

	upd_x = main_data->player.pos_x + main_data->player.dir_y * SPEED * direction;
	upd_y = main_data->player.pos_y - main_data->player.dir_x * SPEED * direction;
	return (validate_move(main_data, upd_x, upd_y));
}

int	move_player(t_main_data *main_data)
{
	int	moved;

	moved = 0;
	if (main_data->player.move_y == 1)
		moved += move_player_fb(data, 1);
	if (main_data->player.move_y == -1)
		moved += move_player_fb(data, -1);
	if (main_data->player.move_x == -1)
		moved += move_player_lr(data, -1);
	if (main_data->player.move_x == 1)
		moved += move_player_lr(data, 1);
	if (main_data->player.rotate != 0)
		moved += rotate_player(main_data, main_data->player.rotate);
	return (moved);
}