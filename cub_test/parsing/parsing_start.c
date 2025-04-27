#include "../inc/cub3d.h"

bool valid_content(char **file_content, t_main_data *main_data)
{
    if (!file_content || !main_data)
        return (false);
    if(!init_main_data(main_data)) 
        return(false);
    if(!validate_textures(file_content, main_data))
        return(false);



    return (true);
}
