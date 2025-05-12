

# define WIN_W 1920
# define WIN_H 1080

typedef enum e_type_textr
{
    NO = 0,
    SO = 1,
    WE,
    EA, 
    F,
    C
} t_type_textr;

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

typedef struct s_main_data
{
    void	*mlx;
	void	*win;
    t_image	img;

    t_texture textures[4];
    t_rgb floor;
    t_rgb ceiling;
    // t_map_digit **map;

    char	**maplines;
	int		map_height;
	int		map_width;
    char    player;
    float   player_x;
    float   player_y;    

    
} t_main_data;