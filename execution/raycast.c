#include "cub3d.h"

void init_raycast(int x, t_ray *ray, t_player *player)
{
	init_ray(&ray);
	ray->camera_x = 2 * x / (double) WIN_W - 1; // camera -1 left 0 and 1
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x; //direction of ray
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int) player->pos_x; //current square of the ray
	ray->map_y = (int) player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x); //distance to go to next x or y
	ray->deltadist_y = fabs(1 / ray->dir_y);

}

void set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0) //left side
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;// distance from start ray start position to next x or y position
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = ( ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0) //left side
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = ( ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

void do_dda(t_main_data *main_data, t_ray *ray)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25 || ray->map_y > main_data->map_height - 0.25 || ray->map_x > main_data->map_width - 1.25)
			break;
		else if(main_data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;

	}
}

void calculate_wall_height (t_ray *ray, t_main_data *main_data, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->wall_height = (int) (WIN_H / ray->wall_dist);
	ray->drw_start = -(ray->wall_height) / 2 + WIN_H / 2;
	if (ray->drw_start < 0)
		ray->drw_start = 0;
	ray->drw_end = ray->wall_height / 2 + WIN_H / 2;
	if (ray->drw_end >= WIN_H)
		ray->drw_end = WIN_H - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else	
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);

}

t_image *select_texture(t_main_data *data, t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x > 0)
		return &data->e_xpm;
	else if (ray->side == 0 && ray->dir_x < 0)
		return &data->w_xpm;
	else if (ray->side == 1 && ray->dir_y > 0)
		return &data->s_xpm;
	else
		return &data->n_xpm;
}

void draw_wall_strip(t_main_data *data, t_ray *ray, int x, t_image *texture)
{
	int y;
	int tex_x;
	int tex_y;
	double step;
	double tex_pos;
	unsigned int color;

	tex_x = (int)(ray->wall_x * (double) texture->w);
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1 && ray->dir_y < 0))
		tex_x = texture->w - tex_x - 1;

	step = 1.0 * texture->h / ray->wall_height;
	tex_pos = (ray->drw_start - WIN_H / 2 + ray->wall_height / 2) * step;

	y = ray->drw_start;
	while (y < ray->drw_end)
	{
		tex_y = (int)tex_pos & (texture->h - 1);
		tex_pos += step;

		color = *(unsigned int *)(texture->buff + (tex_y * texture->line_l + tex_x * (texture->bpp / 8)));
		char *dst = data->img.buff + (y * data->img.line_l + x * (data->img.bpp / 8));
		*(unsigned int *)dst = color;
		y++;
	}
}


void update_render_img(t_main_data *data, t_ray *ray, int x)
{
	t_image *texture;

	texture  = select_texture(data, ray);
	draw_wall_strip(data, ray, x, texture);
}

int raycast(t_main_data *main_data, t_player player)
{
	t_ray ray;
	int x;

	x = 0;
	ray = main_data->ray;
	while (x < WIN_W)
	{
		init_raycast(x, &ray, &player);
		set_dda(&ray, &player);
		do_dda(main_data, &ray);
		calculate_wall_height(&ray, main_data, &player);
		update_render_img(main_data, &ray, x);
		x++;
	}
	return (0);
}

