#include "cub3d.h"

int load_textures(t_main_data *main_data)
{
    main_data->n_xpm.image = mlx_xpm_file_to_image(main_data->mlx, main_data->textures[0].path,
        &main_data->n_xpm.w, &main_data->n_xpm.h);
    main_data->s_xpm.image = mlx_xpm_file_to_image(main_data->mlx, main_data->textures[1].path,
            &main_data->s_xpm.w, &main_data->s_xpm.h);
    main_data->w_xpm.image = mlx_xpm_file_to_image(main_data->mlx, main_data->textures[2].path,
            &main_data->w_xpm.w, &main_data->w_xpm.h);
    main_data->e_xpm.image = mlx_xpm_file_to_image(main_data->mlx, main_data->textures[3].path,
            &main_data->e_xpm.w, &main_data->e_xpm.h);   
       
if (!main_data->n_xpm.image || !main_data->e_xpm.image
    || !main_data->w_xpm.image || !main_data->s_xpm.image)
    return (0);

    //pixel manipulation
    main_data->n_xpm.buff = mlx_get_data_addr(main_data->n_xpm.image,
        &main_data->n_xpm.bpp, &main_data->n_xpm.l_len, &main_data->n_xpm.endian);
    main_data->s_xpm.buff = mlx_get_data_addr(main_data->s_xpm.image,
        &main_data->s_xpm.bpp, &main_data->s_xpm.l_len, &main_data->s_xpm.endian);
    main_data->w_xpm.buff = mlx_get_data_addr(main_data->w_xpm.image,
        &main_data->w_xpm.bpp, &main_data->w_xpm.l_len, &main_data->w_xpm.endian);
    main_data->e_xpm.buff = mlx_get_data_addr(main_data->e_xpm.image,
        &main_data->e_xpm.bpp, &main_data->e_xpm.l_len, &main_data->e_xpm.endian);
    return (1);
    
}

int	render(t_main_data *main_data)
{
	mlx_clear_window(main_data->mlx, main_data->win);
	set_bg(&main_data->img, main_data->ceiling, main_data->floor);
	raycast(main_data, main_data->player);
	mlx_put_image_to_window(main_data->mlx, main_data->win,
		main_data->img.image, 0, 0);
	return (0);
}

void	set_bg(t_image *img, t_rgb ceiling, t_rgb floor)
{
	int x;
    int y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			if (y < WIN_H / 2)
				pixel_put_img(img, x, y, ceiling);
			else
				pixel_put_img(img, x, y, floor);
			y++;
		}
		x++;
	}
}

void	pixel_put_img(t_image *img, int x, int y, t_rgb color)
{
	char	*dst;
	unsigned int pixel;

	if (x < 0 || x >= WIN_W
		|| y < 0 || y >= WIN_H)
		return ;

    if (!color.is_set)
        return;

    // Pack RGB into 0x00RRGGBB format
    pixel = (color.red << 16) | (color.green << 8) | (color.blue);
	dst = img->buff + (y * img->line_l + x * (img->bpp / 8));
	*(unsigned int *)dst = pixel;
}
