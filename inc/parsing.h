typedef enum e_type_textr
{
    NO = 0,
    SO = 1,
    WE,
    EA, 
    F,
    C
} t_type_textr;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// typedef enum e_map_digit{
//     ZERO = 0, 
//     ONE,
//     PLAYER , 
//     SPACE
// } t_map_digit;

typedef struct s_texture
{
    t_type_textr type;
    char *path;
} t_texture;

typedef struct s_image
{
	void	*image;
	char	*buff;
	int		bpp;
	int		line_l;
	int		endian;
	int		w;
	int		h;
}	t_image;

typedef struct s_rgb 
{
    int red;
    int green; 
    int blue;
    bool is_set;
} t_rgb;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		wall_height;
	int		drw_start;
	int		drw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;
typedef struct s_main_data
{
    t_texture textures[4];
    t_rgb floor;
    t_rgb ceiling;
    void	*mlx;
	void	*win;
	t_image	img;
    // t_map_digit **map;

    t_image	n_xpm;
	t_image	e_xpm;
	t_image	w_xpm;
	t_image	s_xpm;
    char	**maplines;
	int		map_height;
	int		map_width;
    t_player    player;//change in parsing 
    float   direction;  

    
} t_main_data;