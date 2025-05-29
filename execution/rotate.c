#include "cube3d.h"


static void	apply_rotation(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
}

int	rotate_player(t_main_data *main_data, double dir)
{
	double	rot_angle;
	int		moved;

	moved = 0;
	if (dir != 0)
	{
		rot_angle = ROTSPEED * dir;
		apply_rotation(&main_data->player.dir_x, &main_data->player.dir_y, rot_angle);
		apply_rotation(&main_data->player.plane_x, &main_data->player.plane_y, rot_angle);
		moved = 1;
	}
	return (moved);
}

static bool	is_valid_pos(t_main_data *main_data, double x, double y)
{
    if (x < 0.25 || x >= main_data->map.width - 1.25)
		return (false);
	if (y < 0.25 || y >= main_data->map.height -0.25)
		return (false);
	return (true);
}

int	validate_move(t_main_data *main_data, double upd_x, double upd_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(main_data, upd_x, main_data->player.pos_y))
	{
		main_data->player.pos_x = upd_x;
		moved = 1;
	}
	if (is_valid_pos(main_data, main_data->player.pos_x, upd_y))
	{
		main_data->player.pos_y = upd_y;
		moved = 1;
	}
	return (moved);
}
